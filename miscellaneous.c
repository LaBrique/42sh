/*
** EPITECH PROJECT, 2017
** misc
** File description:
** misc
*/

#include "mysh.h"

int	argcounter(char **argv)
{
	for (int i = 0; argv; i++) {
		if (!argv[i])
			return (i);
	}
	return (0);
}

char	*get_prompt(void)
{
	char *cwd = char_dim1_malloc(255);
	char home[] = "/home/";

	getcwd(cwd, 255);
	if (cwd[0] == '/' && cwd[1] == 0)
		return (cwd);
	for (int i = 0; i != 6; i++) {
		if (cwd[i] != home[i])
			return (cwd);
	}
	if (cwd[6] == 0)
		return (cwd);
	for (int i = 6; i != my_strlen(cwd); i++) {
		if (cwd[i] == '/') {
			cwd += i + 1;
			return (my_strcat("~/", cwd, 0));
		}
	}
	return ("~");
}

char	**exit_sh(char **arg, char **envp)
{
	if (argcounter(arg) < 2)
		exit(0);
	for (int i = 1; arg[1][i]; i++) {
		if (arg[1][i + 1] && arg[1][i] == ' ') {
			my_printf("exit: Expression Syntax.\n");
			return (envp);
		}
	}
	if (my_str_isnum(arg[1]) == 0) {
		my_printf("exit: Badly formed number.\n");
		return (envp);
	}
	exit(my_getnbr(arg[1]));
}

void	int_ign(int sig)
{
	(void)sig;
	if (isatty(0))
		my_printf("\n\033[1;31m%s\033[0m> ", get_prompt());
}
