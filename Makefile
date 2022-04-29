CC = gcc
CFLAG = -Wall -Wextra -Werror -D BUFFER_SIZE=5

all:
	@$(CC) $(CFLAG) main.c get_next_line.c get_next_line_utils.c
	@#$(CC) -fsanitize=address main.c get_next_line.c get_next_line_utils.c
	@#valgrind --leak-check=full --show-leak-kinds=all ./a.out
	@./a.out

norm:
	@echo "------------------------------------"
	@echo " !!!!!!!!   NORMINETTE   !!!!!!!!"
	@echo ""
	@norminette -R CheckForbiddenSourceHeader *.c
	@norminette -R CheckDefine *.h
	@echo ""
	@echo "------------------------------------"
