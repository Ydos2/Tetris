##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## minishell1's Makefile
##

MAIN	=	./src/main.c

MAIN_OBJ	=	$(MAIN:.c=.o)

SRC	=	src/read_file.c				\
		src/error_handling.c		\
		src/help_page.c				\
		src/arguments_tetris.c		\
		src/tetris_debug.c			\
		src/tetris_game.c			\
		src/set_free.c				\
		src/manage_level.c			\
		src/map.c					\
		src/initialise.c			\

SRC_OBJ	=	$(SRC:.c=.o)

LIB	=	lib/my/my_str_to_array.c	\
		lib/my/my_is_stralphap.c	\
		lib/my/add_line_array.c		\
		lib/my/my_is_str_nbr.c		\
		lib/my/my_freegetnbr.c		\
		lib/my/my_free_array.c		\
		lib/my/my_is_alphap.c		\
		lib/my/my_arraydup.c		\
		lib/my/my_putarray.c		\
		lib/my/my_putchar.c			\
		lib/my/my_strncmp.c			\
		lib/my/my_strcmp.c			\
		lib/my/my_is_nbr.c			\
		lib/my/my_printf.c			\
		lib/my/my_putstr.c			\
		lib/my/my_strlen.c			\
		lib/my/my_putnbr.c			\
		lib/my/my_strdup.c			\
		lib/my/my_strcpy.c			\
		lib/my/my_getnbr.c			\
		lib/my/my_strcat.c			\
		lib/my/my_stradd.c			\
		lib/my/my_calloc.c			\
		lib/my/my_strequbool.c		\
		lib/my/my_itostr.c			\
		lib/my/get_next_line.c

LIB_OBJ	=	$(LIB:.c=.o)

TESTS	=	tests/tests_my_printf_get.c		\
			tests/tests_my_printf_modulo.c	\
			tests/tests_my_printf_set.c		\
			tests/tests_my_printf_start.c	\

TARGET	=	tetris

LIB_NAME	=	libmy.a

TESTS_NAME	=	unit_tests

CFLAGS	=	-I./include -Wall -Wextra -pedantic -fno-builtin -g3

all:	$(TARGET)

call_obj:
	@printf "\033[1;31mCOMPILING LIB...\033[0;39m\n"

%.o: %.c ## Compile the objects
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 41s\n" $@ | tr ' ' '.'

compile_lib:	call_obj $(LIB_OBJ)
	@ar rcs $(LIB_NAME) $(LIB_OBJ)
	@rm ./lib/my/*.o
	@mv $(LIB_NAME) ./lib/
	@printf "\033[1;32mLIB COMPILED\033[0;39m\n"

$(TARGET):	compile_lib $(SRC_OBJ) $(MAIN_OBJ)
	@$(CC) -o $(TARGET) $(MAIN_OBJ) $(SRC_OBJ) ./lib/$(LIB_NAME) $(CFLAGS)
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(SRC_OBJ) | tr ' ' '.'
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "\e[1;32mLINKED ALL SOURCE OBJECT FILES\e[0m\n"
	@find . -type f \( -name "*.o" -o -name "#*#" -o -name "*~" \) -delete

debug:	CFLAGS += -g3
debug:	compile_lib $(SRC_OBJ) $(MAIN_OBJ)
	@$(CC) -o $(TARGET) $(MAIN_OBJ) $(SRC_OBJ) ./lib/$(LIB_NAME) $(CFLAGS)
	@printf "\e[1;32mDEBUG COMPILATION\e[0m\n"
	@find . -type f \( -name "*.o" -o -name "#*#" -o -name "*~" \) -delete

tests_run: compile_lib clean
	@echo -e "\033[1;31mCOMPILING TESTS...\033[0;39m"
	@gcc $(LIB) -L./lib/ -lmy -c --coverage $(CFLAGS)
	@gcc $(TESTS) -c $(CFLAGS)
	@gcc -o $(TESTS_NAME) *.o -lcriterion -lgcov
	@echo -e "\033[1;32mTESTS COMPILED\033[0;39m"
	@echo -e "\033[1;31mEXECUTING TESTS...\033[0;39m"
	@./$(TESTS_NAME)
	@echo -e "\033[1;33mGCOVR LINES\033[0;39m"
	@gcovr --exclude tests/
	@echo -e "\033[1;33mGCOVR BRANCHES\033[0;39m"
	@gcovr --exclude tests/ --branches
	@echo -e "\033[1;32mTESTS COMPLETED\033[0;39m"
	@find . -type f \( -name "*.gcno" -o -name "*.gcda" -o -name "*.o" -o -name "#*#" -o -name "*~" \) -delete

clean:
	@echo -e "\033[1;31mCLEANING UP...\033[0;39m"
	@find . -type f \( -name "*.gcno" -o -name "*.gcda" -o -name "*.o" -o -name "#*#" -o -name "*~" \) -delete
	@echo -e "\033[1;32mCLEANING COMPLETED\033[0;39m"

fclean:	clean
	@rm -f ./lib/$(LIB_NAME)
	@rm -f $(TARGET)
	@rm -f $(TESTS_NAME)
	@echo -e "\033[1;32mCLEANING EXTRA COMPLETED\033[0;39m"

re:	fclean all

.PHONY:	all clean fclean re