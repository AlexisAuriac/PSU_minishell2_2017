/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Transforms the command in an array of string into a binary search tree.
*/

#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include "my.h"
#include "minishell2.h"

bool is_null_command(node_t *node)
{
	return (node->op == EXPR && node->expr[0] == NULL);
}

bool is_op(token_t op, int nb, ...)
{
	va_list ap;

	va_start(ap, nb);
	for (int i = 0 ; i < nb ; ++i) {
		if (op == va_arg(ap, token_t)) {
			va_end(ap);
			return (true);
		}
	}
	va_end(ap);
	return (false);
}

bool check_syntax(node_t *node)
{
	if (node->left) {
		if (!check_syntax(node->left))
			return (false);
	}
	if (node->right) {
		if (!check_syntax(node->right))
			return (false);
	}
	if (node->op != EXPR) {
		if (ERROR_TOKEN[node->op](node->left, node->right))
			return (false);
	}
	return (true);
}