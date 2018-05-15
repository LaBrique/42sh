/*
** EPITECH PROJECT, 2017
** unsetenv
** File description:
** unsetenv
*/

#include "mysh.h"

int	get_env_position(char *name, char **envp)
{
	char *tmp = char_dim1_malloc(255);

	for (int j = 0; envp[j]; j++) {
		for (int k = 0; k != 255; k++)
			tmp[k] = 0;
		for (int k = 0; envp[j][k] != '=' && k <= my_strlen(name); k++)
			tmp[k] = envp[j][k];
		if (my_strcmp(name, tmp))
			return (j);
	}
	return (-1);
}

char	**envp_remove(char *name, char **envp)
{
	int i = argcounter(envp);
	int p = get_env_position(name, envp);
	char **nenvp = malloc(sizeof(char *) * i);

	for (int j = 0; j < p; j++) {
		nenvp[j] = envp[j];
	}
	for (int j = p + 1; envp[j]; j++) {
		nenvp[j - 1] = envp[j];
	}
	nenvp[i - 1] = NULL;
	return (nenvp);
}

char	**unsetenv_sh(char *arg, char **envp)
{
	char **argv = my_char1d_to_char2d(arg, " ");
	int argc = argcounter(argv);

	if (argc == 1 && (argv[0][0] == 0 || argv[0][0] == ' ')) {
		my_printf("unsetenv: Too few arguments.\n");
		return (envp);
	}
	if (argc > 1)
		return (envp);
	if (!get_env(argv[0], envp))
		return (envp);
	else
		return (envp_remove(argv[0], envp));
}
