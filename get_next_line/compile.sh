#gcc -Wall -Werror -Wextra main.c get_next_line.c libft/libft.a -D BUFFER_SIZE=$1

if [ "$#" -eq 2 ]
then
	if [ -e $2 ]
	then
		gcc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=$1
		./a.out $2
	else
		echo "File doesnt exist."
	fi
else
	echo "Wrong number of arguments."
	echo "arg 1 : BUFFER_SIZE, arg2 : FILE PATH"
fi
#gcc -Wall -Werror -Wextra main.c get_next_line.c -D BUFFER_SIZE=$1

#gcc -g3 -fsanitize=address -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=32
