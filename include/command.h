/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** Command parsing header.
*/

#ifndef COMMAND_H
#define COMMAND_H

/* INCLUDE */
#include <fcntl.h>
#include "operators.h"


/* TYPEDEFS */
typedef struct node {
	char *str;
	char **expr;
	int result;
	token_t op;
	struct node *left;
	struct node *right;
} node_t;

typedef struct error_signal {
	int signal;
	int error_value;
	const char *mssg;
} error_signal_t;


/* FUNCTIONS */
//parse_command/ll_parser/tree.c
node_t *create_node(void);
bool create_branchs(node_t *node);
void del_tree(node_t *tree);
void show_tree(node_t *tree);

//lexer/get_command.c
node_t *get_command(shell_t *mysh);

//lexer/ll_lexer.c
const char *get_token(const char *expr, const char * const *tokens);
node_t *ll_lexer(char *command);

//lexer/split_node.c
bool split_node(node_t *node, const char *token, const char * const *tokens);

//lexer/split_expressions.c
bool split_expressions(node_t *node);

//lexer/check_syntax.c
bool is_null_command(node_t *node);
bool is_op(token_t op, int nb, ...);
bool check_syntax(node_t *node);

//parser/exec_tree.c
bool exec_tree(shell_t *mysh, node_t *tree);

//parser/exec_command.c
void exec_command(shell_t *mysh, char **command);

//parser/my_access.c
bool my_access(shell_t *mysh, char *name, char **path);

//parser/my_exec.c
void my_exec(shell_t *mysh, char *path, char **command);


/* CONSTANTS */
static const error_signal_t ERRORS_SIGNAL[] = {
	{8, 136, "Floating exception\n"},
	{11, 139, "Segmentation fault\n"},
	{0}
};

#endif