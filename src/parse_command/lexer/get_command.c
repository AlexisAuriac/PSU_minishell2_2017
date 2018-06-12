/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Recuperates the command from the users' input.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell2.h"

node_t *get_command(shell_t *mysh)
{
	char *line = get_next_line(STDIN_FILENO);
	node_t *tree = NULL;

	if (line == NULL) {
		mysh->stop = true;
		if (mysh->tty)
			my_putstr("exit\n");
		return (NULL);
	}
	tree = ll_lexer(line);
	free(line);
	if (tree == NULL) {
		mysh->exit_status = 1;
		return (NULL);
	}
	return (tree);
}