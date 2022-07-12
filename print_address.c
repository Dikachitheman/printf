#include "main.h"

/**
 * print_address - prints address of input in hex format
 * @args: va_list arguments from _printf()
 * Return: number of char printed
 */

int print_address(va_list args)
{
	char *str;
	unsigned long int p = va_arg(args, unsigned long int);

	register int count = 0;

	if (!p)
		return (puts("(nil)"));
	str = convert(p, 16, 1);
	count += puts("0x"), count += puts(str);
	return (count);
}
