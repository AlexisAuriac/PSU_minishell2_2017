/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Basic tree functions.
*/

#include <stdlib.h>
#include "my.h"
#include "minishell2.h"

node_t *create_node(void)
{
	node_t *new_node = malloc(sizeof(node_t));

	if (new_node == NULL) {
		ERROR_MALLOC;
		return (NULL);
	}
	my_memset(new_node, 0, sizeof(node_t));
	new_node->op = EXPR;
	return (new_node);
}

bool create_branchs(node_t *node)
{
	node->left = create_node();
	if (node->left == NULL)
		return (false);
	node->right = create_node();
	if (node->right == NULL) {
		free(node->left);
		node->left = NULL;
		return (false);
	}
	return (true);
}

void del_tree(node_t *tree)
{
	if (tree->left != NULL)
		del_tree(tree->left);
	if (tree->right != NULL)
		del_tree(tree->right);
	if (tree->expr != NULL)
		my_free_array((void *) tree->expr);
	free(tree);
}