/*
** EPITECH PROJECT, 2017
** command
** File description:
** command
*/

#include "mysh.h"

int	get_input_fd(node_t *tree, int old)
{
	switch (tree->opt) {
		case 1:
		return (old);
		case 2:
		return (old);
		case 3:
		return (old);
		case 4:
		return (old);
		case 5:
		return (open(tree->right->str, O_RDONLY));
		case 6:
		// return (get_double_left())
		break;
	}
	return (0);
}

int	get_output_fd(node_t *tree, int old)
{
	int pipefd[2];

	switch (tree->opt) {
		case 1:
		return (old);
		case 2:
		pipe(pipefd);
		return (pipefd[1]);
		case 3:
		return (open(tree->right->str, O_WRONLY | O_CREAT | O_TRUNC,
		S_IRWXU));
		case 4:
		return (open(tree->right->str, O_WRONLY | O_CREAT | O_APPEND,
		S_IRWXU));
		case 5:
		return (old);
		case 6:
		return (old);
	}
	return (1);
}

int	get_fd(int fd[2], int fd2[2], node_t *tree)
{
	if (tree->opt) {
		fd[0] = get_input_fd(tree, fd[0]);
		fd[1] = get_output_fd(tree, fd[1]);
		fd2[0] = tree->opt == 2 ? fd[1] - 1 : fd[1];
		fd2[1] = 1;
		if (fd[0] == -1 || fd[1] == -1 || fd2[0] == -1)
			return (1);
	}
	return (0);
}

int	execute_commands(node_t *tree, int fd[2], char ***envp, int waiter)
{
	int fd2[2];

	if (!tree)
		return (1);
	waiter = tree->opt == 2 ? 0 : waiter;
	if (tree->str) {
		if (check_builtins(tree->str, envp));
		else
			execute_binary(tree->str, fd, *envp, waiter);
	}
	if (get_fd(fd, fd2, tree))
		return (1);
	if (tree->left)
		if (execute_commands(tree->left, fd, envp, waiter))
			return (1);
	if (tree->right && tree->opt < 3)
		if (execute_commands(tree->right, fd2, envp, 1))
			return (1);
	return (0);
}
