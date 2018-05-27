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

	for (int i = 0; i < argc; i++) {
		if (my_strcmp(argv[i], "-n"))
			end = 1;
		else
			my_printf((i == 0) ? "%s" : " %s", argv[i]);
	}
	if (!end)
		my_printf("\n");
	return (envp);
}
