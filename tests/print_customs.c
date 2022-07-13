#include "main.h"

/**
 * print_S - non printable characters
 * Description: (0 < ASCII value < 32 or >= 127) are printed this way:\x,
 * followed by the
 * ASCII code value in hexadecimal (uppercase - always 2 characters)
 * @args: va_list arguments from _printf()
 * Return: number of character printed
 */
int print_S(va_list args)
{
	int i, count = 0;
	char *str = va_arg(args, char *);
	char *res;

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
	{
		if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
		{
			count += putchar('\\');
			count += putchar('x');
			if (i < 16)
				count += putchar('0');

			res = convert(str[i], 16, 0);
			count += _printf(res);
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
 * Return: number of char printed
 */
int print_rot13(va_list args)
{
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				putchar(out[j]);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			putchar(str[i]);
			count++;
		}
	}
	return (count);
}
