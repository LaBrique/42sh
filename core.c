/*
** EPITECH PROJECT, 2017
** mysh
** File description:
** mysh
*/

#include "mysh.h"

const builtin_t builtins[] = {
	{"exit", &exit_sh},
	{"cd", &cd},
	{"setenv", &setenv_sh},
	{"unsetenv", &unsetenv_sh}
};

void	get_sig_status(int status)
{
	if (WIFSIGNALED(status)) {
		if (WTERMSIG(status) == SIGSEGV)
			my_printf("Segmentation fault");
		if (WTERMSIG(status) == SIGFPE)
			my_printf("Floating exception");
		my_printf(WCOREDUMP(status) ? " (core dumped)\n" : "\n");
	}
}

void	execute_binary(char *str, int fd[2], char **envp, int waiter)
{
	int status;
	char **argv = get_command(str, envp);

	if (!fork()) {
		dup2(fd[0], 0);
		dup2(fd[1], 1);
		execve(argv[0], argv, envp);
	} else {
		if (fd[0] > 2)
			close(fd[0]);
		if (fd[1] > 2)
			close(fd[1]);
		if (waiter)
			wait(&status);
	}
	get_sig_status(status);
}

int	check_builtins(char *com, char ***envp)
{
	char **command = my_char1d_to_char2d(com, " \t");

	for (int i = 0; i < 4; i++) {
		if (my_strcmp(*command, builtins[i].str)) {
			*envp = (*builtins[i].ptr)(com +
			my_strlen(builtins[i].str) + 1, *envp);
			free_2d(command, argcounter(command));
			return (1);
		}
	}
	free_2d(command, argcounter(command));
	return (0);
}

int	get_input(char *buffer)
{
	int eof = 0;

	if (isatty(0))
		my_printf("\033[1;31m%s\033[0m> ", get_prompt());
	eof = read(0, buffer, 255);
	if (eof == 0 && isatty(0))
		return (my_printf("exit\n"));
	else if (eof == 0)
		return (1);
	cut_buffer(buffer);
	return (0);
}

int	shell_prompt(char ***envp)
{
	char buffer[255] = "\0";
	node_t *tree = NULL;

	check_existence();
	if (get_input(buffer))
		return (1);
	tree = parse_command(my_char1d_to_char2d(buffer, ";"), *envp);
	if (!tree)
		return (0);
	execute_commands(tree, (int [2]){0, 1}, envp, 1);
	return (0);
}
