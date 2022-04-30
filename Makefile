CC = gcc
CFLAG = -Wall -Wextra -Werror -D BUFFER_SIZE=10000000

all:
	@$(CC) $(CFLAG) main.c get_next_line.c get_next_line_utils.c
	@valgrind --leak-check=full ./a.out
	@#valgrind --leak-check=full --show-leak-kinds=all ./a.out
	@#./a.out

fsan:
	@$(CC) -fsanitize=address main.c get_next_line.c get_next_line_utils.c
	@./a.out
norm:
	@echo "------------------------------------"
	@echo " !!!!!!!!   NORMINETTE   !!!!!!!!"
	@echo ""
	@norminette -R CheckForbiddenSourceHeader get_next_*.c
	@norminette -R CheckDefine *.h
	@echo ""
	@echo "------------------------------------"
