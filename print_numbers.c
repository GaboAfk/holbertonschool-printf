#include "main.h"

/**
 * print_decR - auxiliar function that prints a decimal number recursivemt.
 * @var: list of arguments.
 * Return: 0 Success. 5 Error.
 */
void print_decR(int var)
{
	char aux;

	if (var / 10)
		print_decR(var / 10);

	aux = (var % 10) + '0';
	write(1, &aux, sizeof(char));
}

/**
 * print_dec - function that prints a decimal number.
 * @var: list of arguments.
 * Return: 0 Success. 4 Error.
 */
int print_dec(va_list var)
{
	int aux = va_arg(var, int);

	if (!aux)
		return (4);

	if (aux < 0)
	{
		write(1, "-", sizeof(char));
		aux = -aux;
	}

	print_decR(aux);

	return (0);
}
