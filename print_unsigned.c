#include "main.h"

/**
 * print_unsigned - prints an unsigned int.
 * @args: va_list arguments from _printf()
 *
 * Return: unsigned int
 */

int print_unsigned(va_list args)
{
	int divisor = 1, i, resp;
	unsigned int n = va_arg(args, unsigned int);

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;

	for (; divisor >= 1; n %= divisor, divisor /= 10)
	{
		resp = n / divisor;
		putchar('0' + resp);
	}
	return (i + 1);
}
