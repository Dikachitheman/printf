#include "main.h"

/**
 * print_spec - selects the right printing function
 * depending on the conversion specifier passed to _printf()
 * @c: character that holds the conversion specifier pointer
 * Description: the function loops through the structs array functs_arr[] to
 * find a match between the specifier passed to _printf
 * and the first element of the struct, and then the appropriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*print_spec(char ch))(va_list)
{
	specptr functs_arr[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_unsigned},
		{"S", print_S},
		{"p", print_address},
		{"r", print_reverse},
		{"R", print_rot13},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX}
	};
	int flags = 14;
	register int i;

	for (i = 0; i < flags; i++)
		if (functs_arr[i].id[0] == ch)
			return (functs_arr[i].fnspec);
	return (NULL);
}
