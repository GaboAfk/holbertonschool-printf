#include "main.h"

/**
 * print_char - function that prints a char.
 * @var: list of arguments.
 * Return: 0 Success. 2 Error.
 */
int print_char(va_list var)
{
	char aux = va_arg(var, int);

	if (!aux)
		return (2);

	write(1, &aux, sizeof(char));

	return (0);
}

/**
 * print_string - function that prints a string.
 * @var: list of argumets.
 * Return: 0 Success. 3 Error.
 */
int print_string(va_list var)
{
	char *aux = va_arg(var, char*);
	int j = 0;

	if (!aux)
		write(1, "(null)", sizeof("(null)"));
	else
		while (aux[j])
		{
			/*write(1, aux, strlen(aux));*/
			write(1, &aux[j], sizeof(char));
			j++;
		}
	return (0);
}
