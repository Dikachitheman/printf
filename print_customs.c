#include "main.h"

/**
 * print_S - non printable characters
 * (0 < ASCII value < 32 or >= 127) are printed this way:\x, followed by the
 * ASCII code value in hexadecimal (uppercase - always 2 characters)
 * @args: va_list arguments from _printf()
 * Return: number of character printed
 */
int print_S(va_list args)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(args, char *);

	if (!s)
		return (puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			puts("\\x");
			count += 2;
			res = convert(s[i], 16, 0);
			if (!res[1])
				count += putchar('0');
			count += puts(res);
		}
		else
			count += putchar(s[i]);
	}
	return (count);
}

/**
 * print_reverse - prints a string in reverse
 * @args: va_list arguments from _printf()
 * Return: length of the printed string
 */
int print_reverse(va_list args)
{
	int i = 0, j;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	while (str[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		putchar(str[j]);

	return (i);
}

/**
 * print_rot13 - encrypts string with rot13
 * @args: va_list arguments from _printf()
 * Return: number of printed char
 */
int print_rot13(va_list args)
{
	int sum = 0;
	char *str, *argument = va_arg(args, char *);

	if (!argument)
	{
		sum += _putsf("%R", 0);
		return (sum);
	}

	str = convert_rot13(argument);
	if (!str)
		return (0);
	sum = _putsf(str, 0);
	free(str);
	return (sum);
}
