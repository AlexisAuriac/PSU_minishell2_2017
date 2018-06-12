/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Handles the pipe '|' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "minishell2.h"

bool error_pipe(node_t *left, node_t *right)
{
	if (is_null_command(left) || is_null_command(right)) {
		ERROR_NULL_COMMAND;
		return (true);
	} else if (is_op(right->op, 2, L_REDIR, L_DBL_REDIR)) {
		ERROR_AMBIGUOUS_INPUT;
		return (true);
	}
	return (false);
}

bool exec_pipe(shell_t *mysh, node_t *left, node_t *right)
{
	int data_channel[2];
	int saves[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};
	pid_t child_process;

	pipe(data_channel);
	child_process = fork();
	if (child_process == 0) {
		close(data_channel[0]);
		dup2(data_channel[1], STDOUT_FILENO);
		exec_tree(mysh, left);
		dup2(saves[1], STDOUT_FILENO);
		exit(mysh->exit_status);
	} else {
		close(data_channel[1]);
		dup2(data_channel[0], STDIN_FILENO);
		exec_tree(mysh, right);
		dup2(saves[0], STDIN_FILENO);
	}
	return (true);
}