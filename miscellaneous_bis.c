/*
** EPITECH PROJECT, 2017
** miscellaneous_bis
** File description:
** miscellaneous_bis
*/

#include "mysh.h"

void	get_sig_status(int status)
{
	int sig = 0;

	if (WIFSIGNALED(status)) {
		if (WTERMSIG(status) == SIGSEGV)
			sig = my_printf("Segmentation fault");
		if (WTERMSIG(status) == SIGFPE)
			sig = my_printf("Floating exception");
		my_printf((WCOREDUMP(status) && sig != 0) ? " (core dumped)\n" : "\n");
	}
}
