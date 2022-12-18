#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct			CommandNode {
	char				*command;
	int					input_fd;
	int					output_fd;
	struct CommandNode	*next;
} 						CommandNode;

// Set the input and output file descriptors for each command
void connect_fds(CommandNode **curr_command, CommandNode *prev_command, CommandNode *commands)
{
	CommandNode *cur;
	int			pipefd[2];

	cur = *curr_command;
	while (cur->next != NULL)
	{
		pipe(pipefd);
		cur->output_fd = pipefd[1];
		cur->next->input_fd = pipefd[0];
		(void)prev_command;
		cur = cur->next;
	}
	cur->output_fd = STDOUT_FILENO;
	cur = commands;
}

// Duplicate the input and output file descriptors and close the original
// file descriptors
void execute_commands(CommandNode **curr_command)
{
	CommandNode *cur;

	cur = *curr_command;
	if (cur->input_fd != STDIN_FILENO) {
		dup2(cur->input_fd, STDIN_FILENO);
		close(cur->input_fd);
	}
	if (cur->output_fd != STDOUT_FILENO) {
		dup2(cur->output_fd, STDOUT_FILENO);
		close(cur->output_fd);
	}
	execlp(cur->command, cur->command, NULL);
	exit(EXIT_FAILURE);
}

// Close the file descriptors that are no longer needed
void close_fds(CommandNode **curr_command)
{
	CommandNode *cur;

	cur = *curr_command;
	if (cur->input_fd != STDIN_FILENO) {
		close(cur->input_fd);
	}
	if (cur->output_fd != STDOUT_FILENO) {
		close(cur->output_fd);
	}
}
void execute_multi_pipe(CommandNode *commands) {
	CommandNode	*prev_command = NULL;
	CommandNode	*curr_command = commands;
	pid_t		pid;
	int			status;

	connect_fds(&curr_command, prev_command, commands);
	while (curr_command != NULL)
	{
		//Child process
		pid = fork();
		if (pid == 0)
			execute_commands(&curr_command);
		else if (pid < 0)
			exit(EXIT_FAILURE);
		// Parent process
		close_fds(&curr_command);
		curr_command = curr_command->next;
	}
	// Wait for all child processes to finish
	while (wait(&status) > 0) {}
}

void	init_fds(CommandNode **curr_command, CommandNode *prev_command)
{
	int 		pipefd[2];
	CommandNode	*cur;

	cur = *curr_command;
	while (cur->next != NULL)
	{
		pipe(pipefd);
		if (prev_command != NULL)
			cur->input_fd = prev_command->output_fd;
		cur->output_fd = pipefd[1];
		cur->next->input_fd = pipefd[0];
		prev_command = cur;
		cur = cur->next;
	}
	if (prev_command != NULL)
		cur->input_fd = prev_command->output_fd;
	cur->output_fd = STDOUT_FILENO;
}

int main()
{

	// Create a linked list of commands
	CommandNode *commands = malloc(sizeof(CommandNode));
	commands->command = "ls";
	commands->next = malloc(sizeof(CommandNode));
	commands->next->command = "wc";
	commands->next->next = malloc(sizeof(CommandNode));
	commands->next->next->command = "wc";
	commands->next->next->next = NULL;

	CommandNode *prev_command = NULL;
	CommandNode *curr_command = commands;
	
	// Initialize the file descriptors of the linked list
	init_fds(&curr_command, prev_command);

	// Execute the commands using a multi-pipe
	execute_multi_pipe(commands);

	return 0;
}
