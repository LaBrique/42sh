/*
** EPITECH PROJECT, 2017
** segfault
** File description:
** segfault
*/

void	sigsegv_ign(int sig)
{
	printf("gotcha bitch :)\n");
}

int	main(int argc, char const *argv[]) {

	signal(11, sigsegv_ign);
	raise(11);
	printf("still running HA!\n");
	return 0;
}
