##
## EPITECH PROJECT, 2017
## minishell2
## File description:
## Makefile for mysh
##

COM_DIR		=	src/parse_command

OP_DIR		=	src/parse_command/operators

BUILT_DIR	=	src/builtins

SRC_COM		=	$(COM_DIR)/tree.c			\
			$(COM_DIR)/lexer/get_command.c		\
			$(COM_DIR)/lexer/ll_lexer.c		\
			$(COM_DIR)/lexer/split_node.c		\
			$(COM_DIR)/lexer/split_expressions.c	\
			$(COM_DIR)/lexer/check_syntax.c		\
			$(COM_DIR)/parser/exec_tree.c		\
			$(COM_DIR)/parser/exec_command.c	\
			$(COM_DIR)/parser/my_access.c		\
			$(COM_DIR)/parser/my_exec.c

SRC_OP		=	$(OP_DIR)/semicolon.c			\
			$(OP_DIR)/pipe.c			\
			$(OP_DIR)/right_dbl_redirection.c	\
			$(OP_DIR)/right_redirection.c		\
			$(OP_DIR)/left_dbl_redirection.c	\
			$(OP_DIR)/left_redirection.c		\

SRC_BUILT	=	$(BUILT_DIR)/builtin_exit.c		\
			$(BUILT_DIR)/builtin_env.c		\
			$(BUILT_DIR)/builtin_setenv.c		\
			$(BUILT_DIR)/builtin_unsetenv.c		\
			$(BUILT_DIR)/builtin_cd.c

SRC		=	src/main.c		\
			src/init.c		\
			src/env.c		\
			src/shell.c

OBJ		=	$(SRC:.c=.o)		\
			$(SRC_COM:.c=.o)	\
			$(SRC_OP:.c=.o)		\
			$(SRC_BUILT:.c=.o)

CPPFLAGS	+=	-I include

CFLAGS		+=	-Wall -Wextra

LDFLAGS		+=	-Llib/ -lmy

NAME		=	mysh

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && cp $(NAME) tests

tests_run:	$(NAME)
		(cd tests; ./tester.sh)

clean	:
		$(RM) -f $(OBJ)

fclean	:	clean
		$(RM) -f $(NAME)
		$(RM) -f tests/$(NAME)

re	:	fclean	all

.PHONY	:	all tests_run clean fclean re
