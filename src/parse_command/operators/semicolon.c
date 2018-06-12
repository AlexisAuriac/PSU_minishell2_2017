/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Handles the semicolon ';' operator.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "minishell2.h"

bool error_semicolon(UNUSED node_t *left, UNUSED node_t *right)
{
	return (false);
}

bool exec_semicolon(shell_t *mysh, node_t *left, node_t *right)
{
	exec_tree(mysh, left);
	exec_tree(mysh, right);
	return (true);
}