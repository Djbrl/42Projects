/* CELEBT09

   The following attributes changes the terminal attributes.

 */
#define _POSIX_SOURCE
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int getkey() {
    int character;
    struct termios orig_term_attr;
    struct termios new_term_attr;

    /* set the terminal to raw mode */
    tcgetattr(fileno(stdin), &orig_term_attr);
    memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 0;
    tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);

    /* read a character from the stdin stream without blocking */
    /*   returns EOF (-1) if no character is available */
    read(0, &character, 10);

    /* restore the original terminal attributes */
    tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);

    return character;
}

int main()
{
    int key;

    /* initialize the random number generator */
    srand(time(NULL));

    for (;;) {
        key = getkey();
        // if (key > 96 && key < 123)
        if (key == 4283163)
            exit(1);
        else if (key == 4348699)
            exit(1);
        else
            (void)key;
        /* terminate loop on ESC (0x1B) or Ctrl-D (0x04) on STDIN */
        // if (key == 0x1B || key == 0x04) {
        //     break;
        // }
        // else {
        //     /* print random ASCII character between 0x20 - 0x7F */
        //     sleep(1);
        //     // key = (rand() % 0x7F);
        //     // printf("%c", ((key < 0x20) ? (key + 0x20) : key));
        // }
    }
    return 0;
}

// int main() {
//   struct termios term1, term2;
//   char buf[500];


//     printf("%c", getkey());

// //   if (tcgetattr(STDIN_FILENO, &term1) != 0)
// //     perror("tcgetattr() error");
// //   else {
// //     while (1)
// //     {
// //         read(0, buf, 100);
// //     printf("the original end-of-file character is x'%02x'\n",
// //            term1.c_cc[VEOF]);
// //     term1.c_cc[VEOF] = 'z';
// //     if (tcsetattr(STDIN_FILENO, TCSANOW, &term1) != 0)
// //       perror("tcsetattr() error");
// //     if (tcgetattr(STDIN_FILENO, &term1) != 0)
// //       perror("tcgetattr() error");
// //     else
// //       printf("the new end-of-file character is x'%02x'\n",
// //              term1.c_cc[VEOF]);
// //     }
// //   }
//   return (0);
// }