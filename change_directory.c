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

int	cd_errors(char *path)
{
	struct stat sb;

	if (stat(path, &sb) == -1)
		return (my_printf("%s: No such file or directory.\n", path));
	if (!S_ISDIR(sb.st_mode))
		return (my_printf("%s: Not a directory.\n", path));
	return (0);
}

void	special_cd_sh(char *path, char *home, char *old)
{
	if (path[0] == '-')
		chdir(old);
	else if (!home)
		my_printf("No $home variable set.\n");
	else
		chdir(home);
}

char	**cd(char **path, char **envp)
{
	char *home = get_env("HOME", envp);
	char *old = get_env("OLDPWD", envp);
	char *current = getcwd(NULL, 255);

	if (!old)
		envp = envp_append("OLDPWD", "\0", envp);
	if (argcounter(path) > 2) {
		my_printf("cd: Too many arguments.\n");
		return (envp);
	}
	path[1] = check_tilde(path[1]);
	if ((path[1][0] == '~' || path[1][0] == '-') && path[1][1] == 0) {
		special_cd_sh(path[1], home, old);
		return (envp);
	}
	if (!cd_errors(path[1]))
		envp = setenv_sh(my_char1d_to_char2d(my_strcat("setenv OLDPWD ",
		current, 0), " "), envp);
	chdir(path[1]);
	return (envp);
}
