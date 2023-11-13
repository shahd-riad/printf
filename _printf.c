#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    convert_match conversion[] = {
        {"%s", printf_string}, {"%c", printf_char}};

    va_list args;
    int i = 0, j, len = 0;

    va_start(args, format);

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    while (format[i] != '\0')
    {
        j = 1;
        while (j <= 1)
        {
            if (conversion[j].id[0] == format[i] && conversion[j].id[1] == format[1])
            {
                len += conversion[j].f(args);
                i += 2;
                goto Here; // to handle having more than 1 specifier
            }
            j--;
        }
        _putchar(*format);
        len++;
        i++;
    }

Here:
    va_end(args);
    return (len);
}

