#include "main.h"
/**
 * print_octal - takes an unsigned int and prints it in binary notation
 * @o: unsigned int to print
 * Return: unsigned int to print
 */
int print_octal(va_list o)
{
	unsigned int a[11];
	unsigned int i, m, n, sum;
	int count;

	n = va_arg(o, unsigned int);
	m = 1073741824; /* (8 ^ 10)*/
	a[0] = n / m;
	for (i = 1; i < 11; i++)
	{
		m /= 8;
		a[i] = (n / m) % 8;
	}
	sum = 0, count = 0;
	for (i = 0; i < 11; i++)
	{
		sum += a[i];
		if (sum || i == 10)
		{
			putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_binary - takes an unsigned int and prints it in binary notation
 * @b: unsigned int to print
 * Return: number of digits printed
 */
int print_binary(va_list b)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	n = va_arg(b, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	sum = 0, count = 0;
	for (i = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}
