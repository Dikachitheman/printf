#include "main.h"

/**
 * print_string - loops through a string and prints every character.
 * @args: va_list arguments from _printf
 *
 * Return: number of characters written
 */
int print_string(va_list args)
{
	int i;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
		putchar(str[i]);

	return (i);
}

/**
 * print_char - prints characters
 * @args: va_list arguments from _printf
 *
 * Return: 1 on success.
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	putchar(c);
	return (1);
}
