#include "main.h"

/**
 * print_binary - prints a number in base 2
 * @args: va_list arguments from _printf()
 *
 * Return: the number to be printed
 */
int print_binary(va_list args)
{
	char *str;
	int j = 0, twos = 1;
	int i, k;

	k = va_arg(args, int);

	str = malloc(sizeof(char) * 32 + 1);
	if (str == NULL)
	        puts("(null)");

	while (i == k)
	{
		if (k < 0)
		{
			str[0] = 1 + '0';
			j++;
			k *= -1;
			i *= -1;
		}

		while (k > 1)
		{
			k /= 2;
			twos *= 2;
		}

		while (twos > 0)
		{
			str[j++] = (i / twos + '0');
			i %= twos;
			twos /= 2;
		}
		str[j] = '\0';

		puts(str);
	}

	return (j);
}
