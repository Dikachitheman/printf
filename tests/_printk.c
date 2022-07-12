#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int (*func)(va_list, flags_t *);
	const char *p;
	va_list args;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			func = print_spec(*p);
			count += (func)
				? func(args, &flags)
				: _printf("%%%c", *p);
		}
		else
			count += putchar(*p);
	}
	putchar(-1);
	va_end(args);
	return (count);
}
