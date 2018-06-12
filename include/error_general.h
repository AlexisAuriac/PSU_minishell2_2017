/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Macros for general errors.
*/

#ifndef ERROR_GENERAL_H
#define ERROR_GENERAL_H

//access
#define ERROR_NOT_FOUND(name)		\
my_printf("%s: Command not found.\n", name)
#define ERROR_PERMISSON(name)		\
my_printf("%s: Permission denied.\n", name)

//system call
#define ERROR_MALLOC		\
my_fputs(2, "Malloc failed\n")
#define ERROR_OPEN		\
my_fputs(2, "Open failed\n")
#define ERROR_DUP2		\
my_fputs(2, "Dup2 failed\n")
#define ERROR_NO_FILE(name)		\
my_printf("%s: No such file or directory.\n", name)

#endif