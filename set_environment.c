/*
** EPITECH PROJECT, 2017
** setenv
** File description:
** setenv
*/

#include "mysh.h"

char	**env_sh(char **argv, char **envp)
{
	if (argv)
		return (envp);
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

int	verif_alpha_num(char **argv)
{
	if (!my_str_isalpha(argv[0]) && !my_str_isnum(argv[0]))
		return (1);
	return (0);
}

int	setenv_error(char **argv, int argc)
{
	if (argc > 2) {
		my_printf(SET_ARG);
		return (3);
	}
	if ((argv[0][0] < 'A' || argv[0][0] > 'Z')
	&& (argv[0][0] < 'a' || argv[0][0] > 'z')) {
		my_printf(SET_LETTER);
		return (1);
	}
	if (!my_str_isalpha(argv[0]) && !my_str_isnum(argv[0])) {
		my_printf(SET_ANUM);
		return (2);
	}
	return (0);
}

char	**setenv_sh(char **argv, char **envp)
{
	int argc = argcounter(++argv);

	if (argc == 0 || (argc == 1 && (argv[0][0] == 0 || argv[0][0] == ' ')))
		return (env_sh(NULL, envp));
	if (setenv_error(argv, argc))
		return (envp);
	if (!get_env(argv[0], envp))
		return (envp_append(argv[0], argv[1], envp));
	else {
		envp = envp_remove(argv[0], envp);
		return (envp_append(argv[0], argv[1], envp));
	}
	return (envp);
}
