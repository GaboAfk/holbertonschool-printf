#include "main.h"
#include <stdio.h>
/**
 * _printf - lkajdlksdjlkdad
 * @format: lajdsslkajdaldj
 * Return: 0 (Success), -1 ERROR.
 */

int _printf(const char *format, ...)
{
	va_list txt;
	int i = 0, count = 0;
/*	int (*function)(va_list);*/

	if (format == NULL)
		return (-1);

	va_start(txt, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%') /* no es '%', procedo a imprimir */
		{
			write(1, &format[i], sizeof(char));
			i++;
			count++;
		}
		else /* tiene un % */
		{
			if (format[i + 1] == '\0')
				return (-1);
			else if (format[i + 1] == '%')
			{
				write(1, &format[i], sizeof(char));
				i++;
				i++;
				count++;
			}
			else if (format[i + 1] == 'c')
			{
				count += print_char(txt);
				i += 2;
			}
			else if (format[i + 1] == 's')
			{
				count += print_string(txt);
				i++;
				i++;
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				count += print_dec(txt);
				i++;
				i++;
			}
			else
			{
				write(1, &format[i], sizeof(char));
				i++;
				write(1, &format[i], sizeof(char));
				i++;
				count++;
				count++;
			}

		/*	if (res != 0) */
		/*		return (res); */
		}
	}

	va_end(txt);
	return (count);
}
