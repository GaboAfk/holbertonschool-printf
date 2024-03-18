/*
 * File: _printf.c
 * Auth: Gabriel Morffe, Pablo Espinola and Micke Lucas.
 */

#include "main.h"
#include <stdlib.h>
#include <unistd.h>

int print_dec(va_list var);

/**
 * _printf - function that produces output according to a format.
 * @format: string with diferents formats.
 * Return: 0 (Success), errors diferents numbers (exit).Falta completar estoXD
 */
int _printf(const char *format, ...)
{
	va_list txt;
	int i = 0, j, count = 0;

	st lts[] =  {
		{'c', print_char},
		{'s', print_string},
		{'d', print_dec},
		{'i', print_dec},
		{'\0', NULL}
	};

	va_start(txt, format);

	while (format && format[i])		/*mientras format existe y contiene algo*/
	{
		if (format[i] == '%')	/* Carlos% */
		{
			i++;
			if (format[i] != '%')
			{
				j = 0;
				while (lts[j].letter != '\0')
				{
					if (format[i] == lts[j].letter)
					{
						if (lts[j].function(txt) != 0)/* si function NO retorna 0 es un error!*/
							return (lts[j].function(txt)); /* imprimo el error */
						else
						{
							i++;
							break;
						}
					}
					j++;
				}
				if (lts[j].letter == '\0') /* si llegué al final, NO COINCIDE el formato. es ERROR*/
					return (-1);
			}
		}
		write(1, &format[i], sizeof(char));
		i++;
		count++;
	}
	return (count);
}
