/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "mysh.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	if (!envp[0]) {
		envp = malloc(sizeof(char *) * 3);
		envp[0] = my_strcat(NULL, D_P, 0);
		envp[1] = my_strcat(NULL, "OLDPWD=", 0);
		envp[2] = NULL;
	}
	signal(SIGINT, int_ign);
	while (shell_prompt(&envp) == 0);
	return (0);
}
