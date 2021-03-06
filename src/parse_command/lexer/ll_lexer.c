/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Transforms the command in an array of string into a binary search tree.
*/

#include <stdlib.h>
#include "my.h"
#include "minishell2.h"

const char *get_token(const char *expr, const char * const *tokens)
{
	int len_token = 0;

	for (int i = 0 ; expr[i] ; ++i) {
		for (int j = 0 ; tokens[j] ; ++j) {
			len_token = my_strlen(tokens[j]);
			if (my_strncmp(expr + i, tokens[j], len_token) == 0)
				return (tokens[j]);
		}
	}
	return (NULL);
}

static bool find_token(node_t *node, const char * const *tokens)
{
	const char *token = NULL;

	if (node->left != NULL)
		find_token(node->left, tokens);
	if (node->right != NULL)
		find_token(node->right, tokens);
	if (node->op == EXPR) {
		token = get_token(node->str, tokens);
		if (token != NULL)
			return (split_node(node, token, tokens));
	}
	return (true);
}

node_t *ll_lexer(char *command)
{
	node_t *root = create_node();

	if (root == NULL)
		return (NULL);
	root->str = command;
	for (int i = 0 ; TOKENS_PRIOR[i] ; ++i) {
		if (!find_token(root, TOKENS_PRIOR[i])) {
			del_tree(root);
			return (NULL);
		}
	}
	if (!split_expressions(root) || !check_syntax(root)) {
		del_tree(root);
		return (NULL);
	}
	return (root);
}
