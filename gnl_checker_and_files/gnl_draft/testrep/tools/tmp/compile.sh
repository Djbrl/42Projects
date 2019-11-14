#gcc -Wall -Werror -Wextra main.c get_next_line.c libft/libft.a -D BUFFER_SIZE=$1

#gcc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=$1
gcc -Wall -Werror -Wextra main.c get_next_line.c -D BUFFER_SIZE=$1

#gcc -g3 -fsanitize=address -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=32
