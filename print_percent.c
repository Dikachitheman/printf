#include "main.h"

/**
 * print_percent - prints percent character [%]
 * @args: va_list args from _printf()
 *
 * Return: percent character
 */
int print_percent(va_list args)
{
	(void)args;
	return (putchar('%'));
}
