#include "main.h"

/**
 * print_int - prints an integer
 * @args: va_list arguments from _printf()
 *
 * Return: number of chars printed.
 */
int print_int(va_list args)
{

	unsigned int divisor = 1, i, resp, len = 0;
	int n = va_arg(args, int);

	if (n < 0)
	{
		putchar('-');
		len++;
		n *= -1;
	}

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;

	for (; divisor >= 1; n %= divisor, divisor /= 10, len++)
	{
		resp = n / divisor;
		putchar('0' + resp);
	}
	return (len);
}

/**
 * print_decimal - prints a decimal
 * @args: va_list arguments from _printf()
 *
 * Return: number of chars printed.
 */
int print_decimal(va_list args)
{
	int a[10];
	int j, m, n, sum, count;

	n = va_arg(args, int);
	count = 0;
	m = 1000000000;
	a[0] = n / m;
	for (j = 1; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}
	if (n < 0)
	{
		putchar('-');
		count++;
		for (j = 0; j < 10; j++)
			a[j] *= -1;
	}
	sum = 0;
	for (j = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum != 0 || j == 9)
		{
			putchar('0' + a[j]);
			count++;
		}
	}
	return (count);
}
