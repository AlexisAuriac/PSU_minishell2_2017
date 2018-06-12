/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** Operators header.
*/

#ifndef OPERATORS_H
#define OPERATORS_H

/* INCLUDE */
#include <fcntl.h>


/* TYPEDEFS */
typedef enum {
	SEMICOLON,
	PIPE,
	R_DBL_REDIR,
	R_REDIR,
	L_DBL_REDIR,
	L_REDIR,
	EXPR
} token_t;

typedef struct node node_t;

/* FUNCTIONS */
//semicolon.c
bool error_semicolon(node_t *left, node_t *right);
bool exec_semicolon(shell_t *mysh, node_t *left, node_t *right);

//pipe.c
bool error_pipe(node_t *left, node_t *right);
bool exec_pipe(shell_t *mysh, node_t *left, node_t *right);

//right_dbl_redirection.c
bool exec_r_dbl_redir(shell_t *mysh, node_t *left, node_t *right);

//right_redirection.c
bool error_r_redir(node_t *left, node_t *right);
bool exec_r_redir(shell_t *mysh, node_t *left, node_t *right);

//left_dbl_redirection.c
bool exec_l_dbl_redir(shell_t *mysh, node_t *left, node_t *right);

//left_redirection.c
bool error_l_redir(node_t *left, node_t *right);
bool exec_l_redir(shell_t *mysh, node_t *left, node_t *right);


/* CONSTANTS */
static const char * const HIGH_PRIORITY[] = {
	";",
	NULL
};

static const char * const LOW_PRIORITY[] = {
	"|",
	">>",
	">",
	"<<",
	"<",
	NULL
};

static const char * const * const TOKENS_PRIOR[] = {
	HIGH_PRIORITY,
	LOW_PRIORITY,
	NULL
};

static const char * const TOKENS[] = {
	";",
	"|",
	">>",
	">",
	"<<",
	"<",
	NULL
};

static bool (*const ERROR_TOKEN[])
(node_t *left, node_t *right) = {
	error_semicolon,
	error_pipe,
	error_r_redir,
	error_r_redir,
	error_l_redir,
	error_l_redir
};

static const int REG_RIGHTS = S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR | S_IWOTH;

static bool (*const TOKENS_EXEC[])
(shell_t *mysh, node_t *left, node_t *right) = {
	exec_semicolon,
	exec_pipe,
	exec_r_dbl_redir,
	exec_r_redir,
	exec_l_dbl_redir,
	exec_l_redir
};


/* ERRORS */
#define ERROR_NULL_COMMAND		\
my_putstr("Invalid null command.\n")
#define ERROR_AMBIGUOUS_OUTPUT		\
my_putstr("Ambiguous output redirect.\n")
#define ERROR_AMBIGUOUS_INPUT		\
my_putstr("Ambiguous input redirect.\n")
#define ERROR_MISSING_NAME_REDIR		\
my_putstr("Missing name for redirect.\n")

#endif