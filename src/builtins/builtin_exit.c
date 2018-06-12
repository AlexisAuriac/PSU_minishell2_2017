/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Quits the shell.
*/

#include "my.h"
#include "minishell2.h"

void builtin_exit(shell_t *mysh, char **command)
{
	int len = my_strlen_tab((void **) command);

	if (len > 2 || (len == 2 && !my_str_is_signednum(command[1]))) {
		ERROR_EXIT_EXPRESSION;
		return;
	}
	else if (len == 2) {
		mysh->exit_status = my_getnbr(command[1]) % 256;
	}
	mysh->stop = true;
	my_putstr("exit\n");
}