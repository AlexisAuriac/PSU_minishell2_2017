/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Handles the right redirection '>' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "minishell2.h"

bool error_r_redir(node_t *left, node_t *right)
{
	if (is_null_command(right)) {
		ERROR_MISSING_NAME_REDIR;
		return (true);
	} else if (is_null_command(left)) {
		ERROR_NULL_COMMAND;
		return (true);
	} else if (is_op(right->op, 5, PIPE, R_REDIR,
		R_DBL_REDIR, L_REDIR, L_DBL_REDIR)) {
		ERROR_AMBIGUOUS_OUTPUT;
		return (true);
	}
	return (false);
}

bool exec_r_redir(shell_t *mysh, node_t *left, node_t *right)
{
	int save_stdout = dup(STDOUT_FILENO);
	int out;

	out = open(right->expr[0], O_WRONLY | O_CREAT | O_TRUNC, REG_RIGHTS);
	if (out == -1) {
		ERROR_OPEN;
		return (false);
	}
	dup2(out, STDOUT_FILENO);
	exec_tree(mysh, left);
	dup2(save_stdout, STDOUT_FILENO);
	close(out);
	return (true);
}