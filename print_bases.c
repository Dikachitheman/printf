#include "main.h"

/**
 * print_binary - prints a number in base 2
 * @args: va_list arguments from _printf()
 *
 * Return: the number to be printed
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 2, 0);

	return (puts(str));
}
