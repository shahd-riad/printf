#include "main.h"

/**
 * print_rev_string - Print a reversed string
 * @list: A va_list containing the arguments
 *
 * Description:
 * This function takes a va_list containing a string argument and prints
 * the characters of the string in reverse order.
 *
 * Parameters:
 *   - @list: A va_list containing the arguments. Expects a string as
 *   an argument.
 *
 * Return:
 *   The number of characters printed (excluding the null byte).
 */
int print_rev_string(va_list list)
{
	int i, size;
	const char *str;

	str = va_arg(list, const char *);

	size = _strlenc(str);

	for (i = size - 1; i >= 0; i--)
		_putchar(str[i]);

	return (size);
}
