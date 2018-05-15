/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** atoi
*/

int	my_getnbr(char const *str)
{
	long number = 0;
	int print_sign = 0;

	if (!str)
		return (0);
	while (*str == '-' || *str == '+')
		*str++ == '-' ? print_sign++ : 0;
	while (*str >= '0' && *str <= '9') {
		number = number * 10;
		number = number + *str++ -48;
		if (number > 2147483647) {
			number = print_sign % 2 == 1 ? number * -1 : number;
			return (number == -2147483648 ? -2147483648 : 0);
		}
	}
	return (print_sign % 2 == 1 ? number * -1 : number);
}
