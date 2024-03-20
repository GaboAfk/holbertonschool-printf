#include "main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: string to print and list of arguments to set and print.
 * Return: 0 (Success), -1 ERROR.
 */

int _printf(const char *format, ...)
{
	va_list txt;
	int i = 0, count = 0, j;

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
		{	i++;/* me posiciono en el char después del %*/
			if (format[i] == '\0') /*ERROR % al final de string*/
				return (-1);
			j = 0;
			while (lts[j].letter) /*mientras esté en una letra del struct*/
			{
				if (*lts[j].letter == format[i]) /*si coincide char con letra*/
				{
					count += lts[j].function(txt);/*ejecuto la funcion ligada y*/
					i++;/*avanzo a la sig letra*/	/*sumo el numero de chars impresos*/
					break;/* si ya coincidió una letra, me salgo del while */
				}
				j++;
			}
			if (lts[j].letter == NULL)	/*recorrí todo el while sin coincidir*/
			{							/*procedo a imprimir % y comando inv*/
				write(1, "%", sizeof(char));
				write(1, &format[i], sizeof(char));
				count += 2;
				i++;
			}
		}
	}
	va_end(txt);
	return (count);
}
