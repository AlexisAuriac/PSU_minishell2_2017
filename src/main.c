/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** Main file.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell2.h"

int main(UNUSED int ac, UNUSED char **av, char **envp)
{
	shell_t mysh = {.env = env_dup(envp), .tty = isatty(STDIN_FILENO)};

	if (mysh.env == NULL)
		return (84);
	shell(&mysh);
	my_free_array((void **) mysh.env);
	return (mysh.exit_status);
}