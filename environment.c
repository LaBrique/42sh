/*
** EPITECH PROJECT, 2017
** env
** File description:
** env
*/

#include "mysh.h"

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

char	*get_full_path(char **paths, char *bin_name)
{
	char *path = char_dim1_malloc(1024);
	char *binary = char_dim1_malloc(my_strlen(bin_name) + 1);

	binary[0] = '/';
	binary[1] = 0;
	bin_name = my_strcat(binary, bin_name, 0);
	if (access(my_strcat(".", bin_name, 0), X_OK) == 0)
		return (my_strcat(".", bin_name, 0));
	for (int i = 0; paths[i]; i++) {
		path = my_strcat(paths[i], bin_name, 0);
		if (access(path, X_OK) == 0)
			return (path);
	}
	my_printf("%s: Command not found.\n", bin_name + 1);
	return (NULL);
}

void	cut_buffer(char *buffer)
{
	for (int i = 0; i != 255; i++) {
		if (buffer[i] == 10)
		buffer[i] = 0;
	}
}

char	**get_command(char *command, char **envp)
{
	char *path = get_env("PATH", envp);
	char **paths;
	char **bin_argv;
	char *bin_path;

	if (!path)
		envp_append("PATH", D_P, envp);
	paths = my_char1d_to_char2d(path, ":");
	bin_argv = my_char1d_to_char2d(command, " ");
	bin_path = get_full_path(paths, bin_argv[0]);
	if (bin_path == NULL)
		return (NULL);
	bin_argv[0] = bin_path;
	return (bin_argv);
}
