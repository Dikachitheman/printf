/**
 * @file state_doc.c
 * @date 2022-07-12
 * 
 * 
 * this file contains the design for the state implementation for the custom printf (_printf)
 * 
 * the idea is to have a compact code to be applicable across all specifiers
 * 
 * The overall syntax of a conversion specification is:

           %[$][flags][width][.precision][length modifier]conversion

 * the program would start with _printf function. 
 * when the arguments has a % symbol -- the state function is called. 
 *    not the spec function
 * the state function checks is (position) = p + 1 is a flag
 * 
 * if true the flag function is called
 * if false, if p + 1 is width, width function is called
 * if false, if p + 1 is precision, precision is called
 * then length is called.
 * 
 * what arguments would state function take?? (va_list)
 * function pointer should be used to access the states.
 * 
 * the args should be va_list args. 
 * the spec function wouldnt be accessed from printf instead from state
 * 
 * the entire args would be checked one after the other.
 * example %4.2ld, 67.0987
 *      = 67.09
 * 
 * va_list would contain the entire elements --
 * 
 * flag not present, flag false.
 * length true in pos + 1, length function would print first four characters
 * precision would check for decimal point, print first two characters
 * long??
 * flag too??
 * 
 * 
 *
 * ****actual code instance******
 * printf ( takes in format specifier, and number of arguments)
 * 
 * as long as element after % isnt % or null -->
 * 
 * int _printf(const char *format, ...)
 * {
 * 
 *      if (postion(%) + 1) == - || +
 *          flag()
 *      if flag is true --> position ++
 *                  else -- > if (postion(%) + 1) == int
 *                            width()
 *      if width is true --> position ++
 *                  else -- > if (postion(%) + 1) == .
 *                            precision()
 *      if precision is true --> position ++
 *                  else -- > if (postion(%) + 1) == l || ll || h
 *                            length()
 * 
 * }
 */


#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int print_int(va_list args);
int print_HEX(va_list args);
int print_binary(va_list args);

typedef struct print_spec
{
	char *id;
	int (*fnspec)(va_list args);
} specptr;

int (*print_spec(char ch))(va_list)
{
	specptr functs_arr[] = {
		// {"c", print_char},
		// {"s", print_string},
		// {"%", print_percent},
		{"d", print_int},
		// {"i", print_int},
		{"b", print_binary},
		// {"u", print_unsigned},
		// {"S", print_S},
		// {"p", print_address},
		// {"r", print_reverse},
		// {"R", print_rot13},
		// {"o", print_octal},
		// {"x", print_hex},
		{"X", print_HEX}
	};
	int flags = 3;
	register int i;

	for (i = 0; i < flags; i++)
		if (functs_arr[i].id[0] == ch)
			return (functs_arr[i].fnspec);
	return (NULL);
}


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

int (*state(char c))(va_list)
{
    int pos;
    int i;
    state = print_spec(pos[i + 1]);
}

int _printf(const char *format, ...)
{
	va_list args;
	int len = 0, i = 0;
	int (*state)(va_list);

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
                state = print_spec(format[i + 1]);
			if (state == NULL)
			{
				putchar(format[i]);
				len++;
				i++;
			}
			else
			{
				len += state(args);
				i += 2;
				continue;
			}
		}
		else
		{
			putchar(format[i]);
			len++;
			i++;
		}
	}
	va_end(args);
	return (len);
}


int main()
{
    printf("%d", 89);
    printf("\n");
    _printf("%d", 89);
    return 0;
}