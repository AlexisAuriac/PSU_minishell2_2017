/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Handles the left double redirection '<<' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <stdbool.h>
#include "my.h"
#include "minishell2.h"

static void get_input_to_redirect(const char *stop, int fd)
{
	char *line = NULL;

	do {
		if (line != NULL) {
			my_fprintf(fd, "%s\n", line);
			free(line);
		}
		my_putstr("? ");
		line = get_next_line(STDIN_FILENO);
	} while (line != NULL && my_strcmp(line, stop));
}

bool exec_l_dbl_redir(shell_t *mysh, node_t *left, node_t *right)
{
	int data_channel[2];
	int save_stdin = dup(STDIN_FILENO);
	pid_t child_pid;

	pipe(data_channel);
	child_pid = fork();
	if (child_pid == 0) {
		close(data_channel[0]);
		get_input_to_redirect(right->expr[0], data_channel[1]);
		exit(mysh->exit_status);
	} else {
		close(data_channel[1]);
		dup2(data_channel[0], STDIN_FILENO);
		waitpid(child_pid, &mysh->exit_status, 0);
		exec_tree(mysh, left);
		dup2(save_stdin, STDIN_FILENO);
	}
	return (true);
}