#include "main.h"

/**
 * print_percent - prints percent character [%]
 * @args: va_list args from _printf()
 *
 * Return: Always 1.
 */
int print_percent(va_list args __attribute__((unused)))
{
	putchar('%');
	return (1);
}
