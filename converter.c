#include "main.h"

/**
 * convert - converts number and base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hex values need to be lowercase
 * Return: result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

/**
 * convert_rot13 - encode using rot13
 * @str: string to encode
 * Return: encoded string
 */
char *convert_rot13(char *str)
{
	int i = 0;
	char *s;
	int len = strlen(str);

	s = malloc(sizeof(char) * len + 1);
	if (!s)
		return (0);

	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' &&
							 str[i] <= 'M'))
			s[i] = str[i] + 13;
		else if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' &&
							      str[i] <= 'Z'))
			s[i] = str[i] - 13;
		else
			s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
