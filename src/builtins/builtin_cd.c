/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Changes the working directory.
*/

#include <stdlib.h>
#include <unistd.h>
#include <linux/limits.h>
#include <sys/stat.h>
#include "my.h"
#include "minishell2.h"

static bool error_cd(char **command)
{
	int nb_arg = my_strlen_tab((void **) command);
	struct stat s;

	if (nb_arg > 2) {
		ERROR_CD_TOO_MUCH_ARG;
		return (true);
	}
	else if (stat(command[1], &s)) {
		ERROR_NO_FILE(command[1]);
		return (true);
	}
	else if (!S_ISDIR(s.st_mode)) {
		ERROR_CD_NOT_DIR(command[1]);
		return (true);
	}
	return (false);
}

static bool cd_home(shell_t *mysh)
{
	int pos = get_pos_env(mysh->env, "HOME");

	if (pos == -1 || chdir(mysh->env[pos] + 5)) {
		ERROR_CD_HOME;
		return (false);
	}
	return (true);
}

static bool cd_back(char **env)
{
	int pos = get_pos_env(env, "OLDPWD");

	if (pos == -1 || chdir(env[pos] + 7)) {
		ERROR_NO_FILE((pos == -1) ? "" : env[pos] + 7);
		return (false);
	}
	return (true);
}

static void update_pwd(shell_t *mysh, char *old_pwd)
{
	char pwd[PATH_MAX + 1] = "";
	char *set_pwd[4] = {"setenv", "PWD", pwd, NULL};

	getcwd(pwd, PATH_MAX);
	builtin_setenv(mysh, set_pwd);
	set_pwd[1] = "OLDPWD";
	set_pwd[2] = old_pwd;
	builtin_setenv(mysh, set_pwd);
}

void builtin_cd(shell_t *mysh, char **command)
{
	char old_pwd[PATH_MAX + 1] = "";
	bool success = false;

	getcwd(old_pwd, PATH_MAX);
	if (command[1] == NULL)
		success = cd_home(mysh);
	else if (my_strcmp(command[1], "-") == 0)
		success = cd_back(mysh->env);
	else if (error_cd(command))
		success = false;
	else
		success = !chdir(command[1]);
	if (success) {
		mysh->exit_status = 0;
		update_pwd(mysh, old_pwd);
	}
	else
		mysh->exit_status = 1;
}