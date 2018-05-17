/*
** EPITECH PROJECT, 2017
** parser.c
** File description:
** parser.c
*/

#include "mysh.h"

short	get_opt(char *str)
{
	if (!str)
		return (0);
	for (int i = 0; str[i]; i++) {
		if (str[i] == '<')
			return (str[i + 1] == '<' ? 6 : 5);
		if (str[i] == '>')
			return (str[i + 1] == '>' ? 4 : 3);
	 	if (str[i] == '|')
			return (2);
	}
	return (-1);
}

node_t	*create_node(char *str)
{
	node_t *new = malloc(sizeof(*new));
	char **blocks = my_char1d_to_char2d(str, "|<>");

	str += str[0] == ' ' ? 1 : 0;
	for (int i = 0; blocks[i]; i++)
		blocks[i] += blocks[i][0] == ' ' ? 1 : 0;
	new->opt = get_opt(str);
	new->str = new->opt == -1 ? *blocks : NULL;
	if (new->str) {
	if (new->str[my_strlen(new->str) - 1] == ' ')
		new->str[my_strlen(new->str) - 1] = 0;
	}
	if (new->opt == -1) {
		new->left = NULL;
		new->right = NULL;
	} else {
		new->right = create_node(str + my_strlen(*blocks) + 1);
		new->left = create_node(blocks[0]);
	}
	return (new);
}

node_t	*parse_command(char **blocks, char **envp)
{
	node_t *tree = malloc(sizeof(*tree));
	int size = argcounter(blocks);

	tree->opt = size > 1 ? 1 : -1;
	tree->str = NULL;
	if (tree->opt == -1) {
		tree->right = NULL;
		tree->left = create_node(*blocks);
	} else {
		tree->left = create_node(*blocks);
		tree->right = parse_command(++blocks, envp);
	}
	return (tree);
}

char	choose_opt(short opt)
{
	switch (opt) {
		case -1:
		return ('-');
		case 1:
		return (';');
		case 2:
		return ('|');
		case 3:
		case 4:
		return ('>');
		case 5:
		case 6:
		return ('<');
	}
	return (0);
}

void	print_tree(node_t *tree)
{
	if (!tree)
		return;
	if (tree->str)
		my_printf("%p: %s\n", tree->str, tree->str);
	my_printf("opt: %c", choose_opt(tree->opt));
	if (tree->opt == 4)
		my_printf(">");
	if (tree->opt == 6)
		my_printf("<");
	my_printf("\n\n");
	if (tree->left) {
		my_printf("left\n");
		print_tree(tree->left);
	}
	if (tree->right) {
		my_printf("right\n");
		print_tree(tree->right);
	}
}
