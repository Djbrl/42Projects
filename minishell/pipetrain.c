// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/wait.h>

// // A linked list node for storing a command and its input/output file descriptors
// typedef struct CommandNode {
//   char *command;
//   int input_fd;
//   int output_fd;
//   struct CommandNode *next;
// } CommandNode;

// // Executes the given linked list of commands using a multi-pipe
// void execute_multi_pipe(CommandNode *commands) {
//   pid_t pid;
//   int status;

//   // Keep track of the current and previous command nodes
//   CommandNode *prev_command = NULL;
//   CommandNode *curr_command = commands;

//   // Create a pipe for each pair of adjacent commands
//   while (curr_command->next != NULL) {
//     int pipefd[2];

//     if (pipe(pipefd) == -1) {
//       perror("pipe");
//       exit(EXIT_FAILURE);
//     }

//     // Set the input and output file descriptors for the current command
//     if (prev_command != NULL) {
//       curr_command->input_fd = prev_command->output_fd;
//     }
//     curr_command->output_fd = pipefd[1];

//     // Set the input file descriptor for the next command in the list
//     curr_command->next->input_fd = pipefd[0];

//     // Move to the next pair of commands in the list
//     prev_command = curr_command;
//     curr_command = curr_command->next;
//   }

//   // Set the input and output file descriptors for the final command in the list
//   if (prev_command != NULL) {
//     curr_command->input_fd = prev_command->output_fd;
//   }
//   curr_command->output_fd = STDOUT_FILENO;

//   // Execute each command in the linked list
//   curr_command = commands;
//   while (curr_command != NULL) {
//     pid = fork();

//     if (pid == 0) {
//       // In the child process, redirect the input and output of the command
//       if (curr_command->input_fd != STDIN_FILENO) {
//         dup2(curr_command->input_fd, STDIN_FILENO);
//         close(curr_command->input_fd);
//       }
//       if (curr_command->output_fd != STDOUT_FILENO) {
//         dup2(curr_command->output_fd, STDOUT_FILENO);
//         close(curr_command->output_fd);
//       }

//       // Execute the command
//       execlp(curr_command->command, curr_command->command, NULL);

//       // If the execution fails, exit with a non-zero exit code
//       exit(EXIT_FAILURE);
//     } else if (pid < 0) {
//       // If fork() fails, exit with a non-zero exit code
//       perror("fork");
//       exit(EXIT_FAILURE);
//     }
//   }
// }
// //

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct CommandNode {
  char *command;
  int input_fd;
  int output_fd;
  struct CommandNode *next;
} CommandNode;

void execute_multi_pipe(CommandNode *commands) {
  pid_t pid;
  int status;

  CommandNode *prev_command = NULL;
  CommandNode *curr_command = commands;

  // Set the input and output file descriptors for each command
  while (curr_command->next != NULL) {
    int pipefd[2];

    if (pipe(pipefd) == -1) {
      perror("pipe");
      exit(EXIT_FAILURE);
    }

    curr_command->output_fd = pipefd[1];
    curr_command->next->input_fd = pipefd[0];

    prev_command = curr_command;
    curr_command = curr_command->next;
  }

  curr_command->output_fd = STDOUT_FILENO;

  curr_command = commands;
  while (curr_command != NULL) {
    pid = fork();

    if (pid == 0) {
      // Duplicate the input and output file descriptors and close the original
      // file descriptors
      if (curr_command->input_fd != STDIN_FILENO) {
        dup2(curr_command->input_fd, STDIN_FILENO);
        close(curr_command->input_fd);
      }
      if (curr_command->output_fd != STDOUT_FILENO) {
        dup2(curr_command->output_fd, STDOUT_FILENO);
        close(curr_command->output_fd);
      }

      execlp(curr_command->command, curr_command->command, NULL);
      exit(EXIT_FAILURE);
    } else if (pid < 0) {
      perror("fork");
      exit(EXIT_FAILURE);
    }

    // Close the file descriptors that are no longer needed
    if (curr_command->input_fd != STDIN_FILENO) {
      close(curr_command->input_fd);
    }
    if (curr_command->output_fd != STDOUT_FILENO) {
      close(curr_command->output_fd);
    }

    curr_command = curr_command->next;
  }

  // Wait for all child processes to finish
  while (wait(&status) > 0) {}
}


int main() {
  // Create a linked list of commands
  CommandNode *commands = malloc(sizeof(CommandNode));
  commands->command = "ls";
  commands->next = malloc(sizeof(CommandNode));
  commands->next->command = "wc";
  commands->next->next = malloc(sizeof(CommandNode));
  commands->next->next->command = "wc";
  commands->next->next->next = NULL;

  // Initialize the file descriptors of the linked list
  CommandNode *prev_command = NULL;
  CommandNode *curr_command = commands;

  while (curr_command->next != NULL) {
    int pipefd[2];

    if (pipe(pipefd) == -1) {
      perror("pipe");
      exit(EXIT_FAILURE);
    }

    if (prev_command != NULL) {
      curr_command->input_fd = prev_command->output_fd;
    }
    curr_command->output_fd = pipefd[1];

    curr_command->next->input_fd = pipefd[0];

    prev_command = curr_command;
    curr_command = curr_command->next;
  }

  if (prev_command != NULL) {
    curr_command->input_fd = prev_command->output_fd;
  }
  curr_command->output_fd = STDOUT_FILENO;

  // Execute the commands using a multi-pipe
  execute_multi_pipe(commands);

  return 0;
}
