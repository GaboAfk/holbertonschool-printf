/*
 * File: _printf.c
 * Auth: Gabriel Morffe, Pablo Espinola and Micke Lucas.
 */

#include "main.h"
#include <unistd.h>
#include <limits.h>

/**
 * print_char - function that print a char.
 * @var: list of arguments.
 */
void print_char(va_list var)
{
	char aux = va_arg(var, int);

	write(1, &aux, sizeof(char));
}

/**
 * print_string - function that print a string.
 * @var: list of arguments.
 */
void print_string(va_list var)
{
	int i = 0;
	char *aux = va_arg(var, char *);

	if (aux)
		while (aux[i])/*recorro *aux mientras exista e imprimo el valor apuntado actual*/
		{
			write(1, &aux[i], sizeof(char));
			i++;
		}
	else
		write(1, "(null)", sizeof("(null)"));

}

/**
 * print_decR - recursive function that print a decimal number.
 *				convert an int to a string to use the write function.
 * @var: number to print.
 */
void print_decR(int var)
{
	char aux;

	if (var < 0)	/*si es negativo, lo vuelvo positivo e imprimo el signo*/
	{
		var = -var;
		write(1, "-", 1);
	}

	if (var / 10 > 0) /*mientras var sea divisible entre 10*/
	{
		print_decR(var / 10); /*le quito el último número y llamo de nuevo a la función*/
		print_decR(var % 10); /*llamo la función con el último número quitado arriba*/
	}
	else		/*cuando ya no es divisible, es solo un digito que puedo convertir con ascii*/
	{
		aux = var + 48;
		write(1, &aux, 1);
	}
}

/**
 * print_dec - function that print a decimal number.
 * @var: list of arguments.
 */
void print_dec(va_list var)
{
	int aux = va_arg(var, int);
	if (aux >= INT_MIN && aux <= INT_MAX) /*verifico que esté dentro de los limites de int*/
		print_decR(aux);
	else
		return;							/*debería romper el printf*/
}

/**
 * _printf - function that produces output according to a format.
 * @format: string with diferents formats.
 * Return: 0 (Success), errors diferents numbers (exit).Falta completar estoXD
 */
int _printf(const char *format, ...)
{
	va_list txt;
	int i = 0, j, chars = 0;
	st format_st[] =  {
		{'c', print_char},
		{'s', print_string},
		{'d', print_dec},
		{'i', print_dec},
		{'\0', NULL}
	};

	va_start(txt, format);
	while (format[i])		/*recorre mientras format existe y contiene algo*/
	{
		if (format[i] == '%')
		{
			i++;
			j = 0;
			if (format[i] != '%')	/*verifico que no sea %%*/
			{
				while (format_st[j].letter != '\0')		/*recorro format_st en busca*/
				{											/*del formato dado*/
					if (format_st[j].letter == format[i])/*si coincide el formato*/
					{
						format_st[j].function(txt);		/*ejecuto su función asociada*/
						i++;
						break;/*me salgo del while para evitar erorres*/
					}						/*un posible error sería "Qu%cso",'e'*/
					j++;					/*ya que ejecutaría format_st en 'c' y tambien en 's'*/
				}
				if (format_st[j].letter == '\0') /*recorrió todo format_st sin conseguir */
					return (-1);						/*el formato adecuado*/
			}
		}
		write(1, &format[i], sizeof(char));
		chars++;
		i++;
	}
	return (chars);
}
