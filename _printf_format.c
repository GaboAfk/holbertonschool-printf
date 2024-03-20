#include "main.h"
/**
 * _printf_struct - auxiliar function use to print before a format call..
 * @letter: letter of format.
 * @txt: list of arguments.
 * Return: number of bytes printed (Success), -1 ERROR.
 */

int _printf_struct(char letter, va_list txt)
{
	int j, count = 0;

	st lts[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_dec},
		{"i", print_dec},
		{"%", print_mod},
		{NULL, NULL}
	};

	j = 0;
	while (lts[j].letter) /*mientras esté en una letra del struct */
	{
		if (*lts[j].letter == letter) /*si coincide char con la letra dada*/
		{
			count += lts[j].function(txt);/*ejecuto la funcion ligada y*/
											/*sumo el numero de chars impresos*/
			break;/* si ya coincidió una letra, me salgo del while */
		}
		j++;
	}

	if (lts[j].letter == NULL)	/*recorrí todo el while sin coincidir*/
	{							/*procedo a imprimir % y comando invalido*/
		write(1, "%", sizeof(char));
		write(1, &letter, sizeof(char));
		count += 2;
	}
	return (count);
}
