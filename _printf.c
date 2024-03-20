#include "main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: string to print and list of arguments to set and print.
 * Return: nummber of bytes printed (Success), -1 ERROR.
 */

int _printf(const char *format, ...)
{
	va_list txt;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);
	va_start(txt, format);

	while (format[i] != '\0') /*recorro el string format*/
	{
		if (format[i] != '%') /* no es '%', procedo a imprimir */
		{
			write(1, &format[i], sizeof(char));
			count++;
			i++;
		}
		else /* tiene un % ENTRO EN MODO CARLOS% */
		{
			i++;/* me posiciono en la letra después del %*/

			if (format[i] == '\0') /*ERROR % al final de string*/
				return (-1);
			/*uso funcion auxiliar para imprimir los casos de formato*/
			/*le paso la letra a evaluar y la lista de argumentos a usar*/
			count += _printf_struct(format[i], txt);
			i++; /*ya imprimí el formato correspondiente*/
					/*avanzo a la siguiente letra*/
		}
	}
	va_end(txt);
	return (count);
}
