#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	convert_match conv[] = {{"%s", printf_string}, {"%c", printf_char}};
	va_list args;
	int i = 0, len = 0, j = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			while (j <= 1)
			{
				if (conv[j].id[0] == format[i] && conv[j].id[1] == format[i + 1])
				{
					len += conv[j].f(args);
					i += 2;
					break;
				}
				j++;
			}
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			len++;
			i += 2;
		}
		else
		{
			_putchar(format[i]);
			len++;
			i++;
		}
	}

	va_end(args);
	return (len);
}

