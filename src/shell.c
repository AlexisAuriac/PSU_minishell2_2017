/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Heart of the project.
*/

#include <stdlib.h>
#include <unistd.h>
#include <linux/limits.h>
#include "my.h"
#include "minishell2.h"

void display_prompt(void)
{
	char path[PATH_MAX + 1] = "";
	int offset = 0;

	getcwd(path, PATH_MAX);
	offset = my_rindex('/', path);
	my_printf("(minishell2 %s)$ ", path + offset + 1);
}

void shell(shell_t *mysh)
{
	node_t *tree = NULL;

	while (!mysh->stop) {
		if (mysh->tty)
			display_prompt();
		tree = get_command(mysh);
		if (tree != NULL) {
			exec_tree(mysh, tree);
			del_tree(tree);
		}
	}
}