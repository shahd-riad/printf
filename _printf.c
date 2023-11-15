#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	convert_match conv[] = {{"%s", printf_string}, {"%c", printf_char},
		{"%i", printf_int}, {"%d", printf_dec}, {"%b", printf_bin},
		{"%%", printf_perc},  {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%r", print_rev_string}};
	va_list args;
	int i = 0, len = 0, j = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
Here:
	while (format[i] != '\0')
	{
		j = 10;
		while (j >= 0)
		{
			if (conv[j].id[0] == format[i] && conv[j].id[1] == format[i + 1])
			{
				len += conv[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
