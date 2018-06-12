/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Header file for builtins.
*/

#ifndef BUILTINS_H
#define BUILTINS_H

/* TYPEDEF */
typedef struct builtin {
	const char *name;
	void (*ptr)(shell_t *mysh, char **command);
} builtin_t;


/* FUNCTIONS */
//builtin_exit.c
void builtin_exit(shell_t *mysh, char **command);

//builtin_env.c
void builtin_env(shell_t *mysh, char **command);

//builtin_setenv.c
void builtin_setenv(shell_t *mysh, char **command);

//builtin_unsetenv.c
void builtin_unsetenv(shell_t *mysh, char **command);

//builtin_cd.c
void builtin_cd(shell_t *mysh, char **command);


/* CONSTANTS */
static const builtin_t BUILTINS[] = {
	{"exit", builtin_exit},
	{"env", builtin_env},
	{"setenv", builtin_setenv},
	{"unsetenv", builtin_unsetenv},
	{"cd", builtin_cd}
};

static const int NB_BUILTINS = 5;


/* ERRORS */
//exit
#define ERROR_EXIT_EXPRESSION		\
my_putstr("exit: Expression Syntax.\n")

//setenv
#define ERROR_SETENV_TOO_MANY_ARG		\
my_putstr("setenv: Too many arguments.\n")
#define ERROR_SETENV_FIRST_CHAR		\
my_putstr("setenv: Variable name must begin with a letter.\n")
#define ERROR_SETENV_ALPHA_NUM		\
my_putstr("setenv: Variable name must contain alphanumeric characters.\n")

//unsetenv
#define ERROR_UNSETENV_TOO_FEW_ARG		\
my_putstr("unsetenv: Too few arguments.\n")

//cd
#define ERROR_CD_HOME		\
my_putstr("cd: Can't change to home directory.\n")
#define ERROR_CD_TOO_MUCH_ARG		\
my_putstr("cd: Too many arguments.\n")
#define ERROR_CD_NOT_DIR(name)		\
my_printf("%s: Not a directory.\n", name)

#endif