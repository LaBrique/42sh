/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** echo
*/

#include "mysh.h"

char	**echo_sh(char **argv, char **envp)
{
	int argc = argcounter(++argv);
	int end = 0;

	for (int i = 1; j < argc; j++) {
		if (my_strcmp(argv[i], "-n"))
			end = 1;
		else
			my_printf(i == 1 ? "%s" : " %s");
	}
	if (end)
		my_printf("\n");
	return (envp);
}

/*
int	is_in_env(char *name, char **envp)
{
	char *var_name = char_dim1_malloc(0);

	for (int i = 0; envp[i]; i++) {
		for (int j = 0; envp[i][j] != '='; j++) {
			var_name = my_realloc(var_name, j + 1, j + 2);
			var_name[j] = envp[i][j];
		}
		if (my_strcmp(var_name, name)) {
			return (1);
		}
	}
	return (0);
}


char	*get_env_value(char **envp, int i)
{
	int j = 0;

	while (envp[i][j] != '=')
		j++;
	j++;
	return (envp[i] + j);
}

char	*get_env(char *name, char **envp)
{
	char *var_name = char_dim1_malloc(0);

	for (int i = 0; envp[i]; i++) {
		for (int j = 0; envp[i][j] != '='; j++) {
			var_name = my_realloc(var_name, j + 1, j + 2);
			var_name[j] = envp[i][j];
		}
		if (my_strcmp(var_name, name)) {
			return (get_env_value(envp, i));
		}
	}
	return (NULL);
}
*/
