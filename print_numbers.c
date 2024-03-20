#include "main.h"
#include <limits.h>

/**
 * print_decR - auxiliar function that prints a decimal number recursivemt.
 * @var: list of arguments.
 * @count: pointer to numbers count.
 * Return: 0 Success. 5 Error.
 */
void print_decR(int var, int *count)
{
	char aux;

	if (var / 10)
		print_decR(var / 10, count);

	aux = (var % 10) + '0';
	write(STDOUT_FILENO, &aux, sizeof(char));
	*count += 1;
}

/**
 * print_dec - function that prints a decimal number.
 * @var: list of arguments.
 * Return: 0 Success. 4 Error.
 */
int print_dec(va_list var)
{
	int aux = va_arg(var, int);
	int count = 0, last = aux % 10;

	aux /= 10;

	if (last < 0)
	{
		write(1, "-", sizeof(char));
		count++;
		aux *= -1;
		last *= -1;
	}

	if (aux)
		print_decR(aux, &count);

	print_decR(last, &count);
	return (count);
}
