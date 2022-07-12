#include "main.h"

/**
 * print_binary - converts an unsigned int argument into binary
 * @args: va_list arguments from _printf()
 * Return: the number of char printed
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 2, 0);

	return (puts(str));
}
