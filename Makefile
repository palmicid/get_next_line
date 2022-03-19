CC = gcc
CFLAG = -Wall -Wextra -Werror -D BUFFER_SIZE=5

all:
	@$(CC) $(CFLAG) main.c get_next_line.c get_next_line_utils.c
	@#$(CC) -fsanitize=address main.c get_next_line.c get_next_line_utils.c
	valgrind --leak-check=full ./a.out
