/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Displays the env.
*/

#include "my.h"
#include "minishell2.h"

void builtin_env(shell_t *mysh, UNUSED char **command)
{
	for (int i = 0 ; mysh->env[i] ; ++i)
		my_printf("%s\n", mysh->env[i]);
	mysh->exit_status = 0;
}