/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Handles the environnement.
*/

#include <stdlib.h>
#include "my.h"
#include "minishell2.h"

static char **env_cpy(char **cpy, char **envp)
{
	for (int i = 0 ; envp[i] ; ++i) {
		cpy[i] = my_strdup(envp[i]);
		if (cpy[i] == NULL) {
			ERROR_MALLOC;
			while (i--)
				free(cpy[i]);
			free(cpy);
			return (NULL);
		}
	}
	return (cpy);
}

char **env_dup(char **envp)
{
	int nb_vars = 0;
	char **cpy = NULL;

	nb_vars = my_strlen_tab((void **) envp);
	cpy = malloc(sizeof(char *) * (nb_vars + 1));
	if (cpy == NULL) {
		ERROR_MALLOC;
		return (NULL);
	}
	cpy[nb_vars] = NULL;
	cpy = env_cpy(cpy, envp);
	return (cpy);
}

int get_pos_env(char **env, char *name)
{
	int len = my_strlen(name);

	for (int i = 0 ; env[i] ; ++i) {
		if (my_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (i);
	}
	return (-1);
}