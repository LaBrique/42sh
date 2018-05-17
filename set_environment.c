/*
** EPITECH PROJECT, 2017
** setenv
** File description:
** setenv
*/

#include "mysh.h"

char	**env_sh(char **envp)
{
	for (int i = 0; envp[i]; i++)
		my_printf("%s\n", envp[i]);
	return (envp);
}

char	**envp_append(char *name, char *value, char **envp)
{
	int i = argcounter(envp);
	char **nenvp = malloc(sizeof(char *) * (i + 2));

	for (int j = 0; j < i; j++)
		nenvp[j] = envp[j];
	nenvp[i] = my_strcat(my_strcat(name, "=", 0), value, 0);
	nenvp[i + 1] = NULL;
	return (nenvp);
}

char	**setenv_sh(char **argv, char **envp)
{
	int argc = argcounter(++argv);

	if (argc == 1 && (argv[0][0] == 0 || argv[0][0] == ' '))
		return (env_sh(envp));
	if (argc > 2) {
		my_printf("setenv: Too many arguments.\n");
		return (envp);
	}
	if (!get_env(argv[0], envp))
		return (envp_append(argv[0], argv[1], envp));
	else {
		envp = envp_remove(argv[0], envp);
		return (envp_append(argv[0], argv[1], envp));
	}
	return (envp);
}
