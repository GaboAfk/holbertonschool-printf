/*
 * File: _printf.c
 * Auth: Gabriel Morffe, Pablo Espinola and Micke Lucas.
 */

#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - function that produces output according to a format.
 * format: string with diferents formats.
 * Return: 0 (Success), errors diferents numbers (exit).Falta completar estoXD
 */
int _printf(const char *format, ...)
{
	va_list txt;
	int i = 0;
	char aux_c;
	char *aux_s;
	va_start(txt, format);

	while (format[i])		/*recorro format mientras existe y contiene algo*/
	{
		if (format[i] == '%') /*si consigue %*/
		{
			i++;
			switch (format[i])		/*ejecuto caso correspondiente al comando recibido*/
			{
			case 'c':
				aux_c = va_arg(txt, int);
				write(1, &aux_c, sizeof(char));
				break;

			case 's':
				aux_s = va_arg(txt, char *);
				while (aux_s)
				{
					write(1, aux_s, 1);
					aux_s++;
				}
				break;

			case 'd':
				/*la funcion es demasiado grande para ir en un case*/
				break;

			case 'i':
				/*la funcion es demasiado grande para ir en un case*/
				break;

			default:
				return (1);
			}
		i++;
		}
		write(1, &format[i], sizeof(char));
		i++;
	}
	va_end(txt);

	return (0);
}
