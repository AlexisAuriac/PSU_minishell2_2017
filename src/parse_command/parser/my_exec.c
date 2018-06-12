/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Executes a program from a path in the PATH.
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "my.h"
#include "minishell2.h"

void my_exec(shell_t *mysh, char *path, char **command)
{
	pid_t child_pid = -1;

	child_pid = fork();
	if (child_pid == 0) {
		execve(path, command, mysh->env);
		perror("execve");
		exit(1);
	}
	waitpid(child_pid, &mysh->exit_status, 0);
	mysh->exit_status %= 128;
	for (int i = 0 ; ERRORS_SIGNAL[i].signal ; ++i) {
		if (mysh->exit_status == ERRORS_SIGNAL[i].signal) {
			mysh->exit_status = ERRORS_SIGNAL[i].error_value;
			my_putstr(ERRORS_SIGNAL[i].mssg);
			break;
		}
	}
}