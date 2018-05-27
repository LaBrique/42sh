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
	{"unsetenv", &unsetenv_sh},
	{"echo", &exit_sh},
	{"env", &env_sh}
};

void	execute_binary(char *str, int fd[2], char **envp, int waiter)
{
	int status = 0;
	char **argv = get_command(str, envp);

	if (!argv)
		return;
	if (!fork()) {
		dup2(fd[0], 0);
		dup2(fd[1], 1);
		execve(argv[0], argv, envp);
	} else {
		if (fd[0] > 2)
			close(fd[0]);
		if (fd[1] > 2)
			close(fd[1]);
	}
	free_2d(argv, argcounter(argv));
	while (waiter && wait(&status) > 0);
	get_sig_status(status);
}

int	check_builtins(char *com, int fd[2], char ***envp)
{
	char **command = my_char1d_to_char2d(com, " \t");
	int success = 0;
	int save_stdin = 0;
	int save_stdout = 0;

	for (int i = 0; i < BUILTIN_NB; i++) {
		if (my_strcmp(*command, builtins[i].str)) {
			save_stdin = dup(STDIN_FILENO);
			save_stdout = dup(STDOUT_FILENO);
			dup2(fd[0], 0);
			dup2(fd[1], 1);
			*envp = (*builtins[i].ptr)(command, *envp);
			success = 1;
			dup2(save_stdin, 0);
			dup2(save_stdout, 1);
		}
	}
	free_2d(command, argcounter(command));
	return (success);
}

int	get_input(char **buffer)
{
	int eof = 0;

	if (isatty(0))
		my_printf("\033[1;31m%s\033[0m> ", get_prompt());
	eof = read(0, *buffer, 255);
	if (eof == 0 && isatty(0))
		return (my_printf("exit\n"));
	else if (eof == 0 || cut_buffer(*buffer))
		return (1);
	*buffer = remove_separators(*buffer, " \t", ";><|");
	return (0);
}

int	shell_prompt(char ***envp)
{
	char *buffer = char_dim1_malloc(255);
	node_t *tree = NULL;

	if (!buffer || get_input(&buffer))
		return (1);
	if (!buffer[0] || buffer[0] == 10)
		return (0);
	tree = parse_command(my_char1d_to_char2d(buffer, ";"), *envp);
	if (!tree || execute_commands(tree, (int [2]){0, 1}, envp, 1))
		return (0);
	return (0);
}
