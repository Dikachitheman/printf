#include "main.h"

/**
 * print_HEX - prints unsigned int to hexadecimal(uppercase)
 * @args: va_list arguments from _printf()
 * Return: number of char printed
 */
int print_HEX(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int num2;
	char c = 'A';
	int i, j, remainder, nbrCharacters = 0;
	char *numhex;

	for (num2 = num; num2 != 0; nbrCharacters++, num2 /= 16)
		;

	numhex = malloc(nbrCharacters);
	for (i = 0; num != 0; i++)
	{
		remainder = num % 16;
		if (remainder < 10)
			numhex[i] = remainder + '0';
		else
			numhex[i] = remainder - 10 + c;
		num = num / 16;
	}
	for (j = i - 1; j >= 0; j--)
		putchar(numhex[j]);
	free(numhex);
	return (nbrCharacters);
}

/**
 * print_hex - prints unsigned int to hexadecimal(lowercase)
 * @args: va_list arguments from _printf()
 * Return: number of char printed
 */
int print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int num2;
	char c = 'a';
	int i, j, remainder, nbrCharacters = 0;
	char *numhex;

	for (num2 = num; num2 != 0; nbrCharacters++, num2 /= 16)
		;

	numhex = malloc(nbrCharacters);
	for (i = 0; num != 0; i++)
	{
		remainder = num % 16;
		if (remainder < 10)
			numhex[i] = remainder + '0';
		else
			numhex[i] = remainder - 10 + c;
		num = num / 16;
	}
	for (j = i - 1; j >= 0; j--)
		putchar(numhex[j]);
	free(numhex);
	return (nbrCharacters);
}


/**
 * print_binary - prints number in binary.
 * @args: list containing octal number to be printed
 * Return: number of octals printed
 */

int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int copy;
	char *bin;
	int i, j, charPrinted = 0;

	if (num == 0)
		return (putchar('0'));
	for (copy = num; copy != 0; j++)
	{
		copy = copy / 2;
	}
	bin = malloc(j);
	if (!bin)
		return (-1);

	for (i = j - 1; i >= 0; i--)
	{
		bin[i] = num % 2 + '0';
		num = num / 2;
	}

	for (i = 0; i < j && bin[i] == '0'; i++)
		;
	for (; i < j; i++)
	{
		putchar(bin[i]);
		charPrinted++;
	}
	free(bin);
	return (charPrinted);
}

/**
 * print_octal - prints number in octal base.
 * @args: list containing octal number to be printed
 * Return: number of octals printed
 */

int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int copy;
	char *octa;
	int i, j, charPrinted = 0;

	if (num == 0)
		return (putchar('0'));
	for (copy = num; copy != 0; j++)
	{
		copy = copy / 8;
	}
	octa = malloc(j);
	if (!octa)
		return (-1);

	for (i = j - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}

	for (i = 0; i < j && octa[i] == '0'; i++)
		;
	for (; i < j; i++)
	{
		putchar(octa[i]);
		charPrinted++;
	}
	free(octa);
	return (charPrinted);
}
