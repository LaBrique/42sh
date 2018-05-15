/*
** EPITECH PROJECT, 2017
** misc
** File description:
** misc
*/

#include "mysh.h"

int	argcounter(char **argv)
{
	int i = 0;

	if (!argv)
		return (0);
	while (argv[i++]);
	return (--i);
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

char	**exit_sh(char *arg, char **envp)
{
	for (int i = 1; arg[i]; i++) {
		if (arg[i + 1] && arg[i] == ' ') {
			my_printf("exit: Expression Syntax.\n");
			return (envp);
		}
	}
	if (my_str_isnum(arg) == 0) {
		my_printf("exit: Badly formed number.\n");
		return (envp);
	}
	exit(my_getnbr(arg));
}

void	check_existence(void)
{
	char wd[255] = "\0";

	getcwd(wd, 255);
	if (wd[0] == 0)
		chdir("..");
}

void	int_ign(int sig)
{
	(void)sig;
	if (isatty(0))
		my_printf("\n\033[1;31m%s\033[0m> ", get_prompt());
}
