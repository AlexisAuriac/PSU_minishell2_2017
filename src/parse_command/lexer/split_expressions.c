/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Splits the strings at the extremities of the tree into arrays of strings.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "minishell2.h"

bool split_expressions(node_t *node)
{
	if (node->left != NULL) {
		if (!split_expressions(node->left))
			return (false);
	}
	if (node->right != NULL) {
		if (!split_expressions(node->right))
			return (false);
	}
	if (node->op == EXPR) {
		node->expr = my_str_split(node->str, SEP_CHARS);
		if (node->expr == NULL) {
			ERROR_MALLOC;
			return (false);
		}
	}
	return (true);
}