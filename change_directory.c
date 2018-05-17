/*
** EPITECH PROJECT, 2017
** cd
** File description:
** cd
*/

#include "mysh.h"

char	*check_tilde(char *path)
{
	if (!path)
		path = char_dim1_malloc(2);
	if (!path[0]) {
		path[0] = '~';
		path[1] = 0;
	}
	return (path);
}

void	append_history(char **history, int *i)
{
	getcwd(history[*i], 40);
	*i += 1;
	if (*i == 502) {
		history[0] = history[501];
		*i = 1;
	}
}

void	special_cd_sh(char *path, char **history, int *entry, char *home)
{
	if (path[0] == '-') {
		chdir(history[*entry - 2]);
		append_history(history, entry);
	}
	else if (!home)
		my_printf("No $home variable set.\n");
	else {
		chdir(home);
		append_history(history, entry);
	}
}

char	**cd(char **path, char **envp)
{
	char *home = get_env("HOME", envp);
	static char **history = NULL;
	static int entry = 0;

	if (argcounter(path) > 2) {
		my_printf("cd: Too many arguments.\n");
		return (envp);
	}
	path[1] = check_tilde(path[1]);
	if (history == NULL) {
		history = char_dim2_malloc(40, 502);
		history[entry] = getcwd(history[entry], 40);
		entry++;
	}
	if ((path[1][0] == '~' || path[1][0] == '-') && path[1][1] == 0) {
		special_cd_sh(path[1], history, &entry, home);
		return (envp);
	}
	if (chdir(path[1]) == -1)
		my_printf("cd: \"%s\" no such directory.\n", path[1]);
	append_history(history, &entry);
	return (envp);
}
