#include "main.h"

/**
 * print_S - non printable characters
 * Description: (0 < ASCII value < 32 or >= 127) are printed this way:\x, followed by the
 * ASCII code value in hexadecimal (uppercase - always 2 characters)
 * @args: va_list arguments from _printf()
 * Return: number of character printed
 */
int print_S(va_list args)
{
	int i;
	char *str = va_arg(args, char*);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
	{
		if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
		{
			putchar('\\');
			putchar('x');
			if (i < 16)
				putchar('0');

			print_HEX(str[i]);
		}
		else
			putchar(str[i]);
	}

	return (i);
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
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(args, char *);

	for (j = 0; s[j] != '\0'; j++)
	{
		i = 0;
		while (rot13[i] != '\0' && s[j] != rot13[i])
			i++;

		if (s[j] == rot13[i])
			putchar(ROT13[i]);
	}

	return (j);
}
