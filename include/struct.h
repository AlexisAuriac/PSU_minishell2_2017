/*
** EPITECH PROJECT, 2017
** minishell2
** File description:
** Structures header file.
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct shell {
	char **env;
	int tty;
	int exit_status;
	bool stop;
} shell_t;

#endif