#include "main.h"

/**
 * print_char - function that prints a char.
 * @var: list of arguments.
 * Return: 0 Success. 2 Error.
 */
int print_char(va_list var)
{
	char aux = va_arg(var, int);

	write(1, &aux, sizeof(char));
	return (1);
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
		aux = "(null)";

	while (aux[j])
	{
		write(1, &aux[j], sizeof(char));
		j++;
	}
	return (j);
}

/**
 * print_mod - function that prints a char.
 * @var: unused list of arguments.
 * Return: 0 Success.
 */
int print_mod(va_list var)
{
	(void)var;
	write(1, "%", sizeof(char));
	return (1);
}

/**
 * error - function give back a error.
 * @var: unused list of arguments.
 * Return: -1.
 */
int error(va_list var)
{
	(void)var;
	return (-1);
}

