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
        {"%s", printf_string}, {"%c", printf_char},
        {"%%", printf_37},
        {"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
        {"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
        {"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
        {"%S", printf_exclusive_string}, {"%p", printf_pointer}
    };

    va_list args;
    int i = 0, len = 0;

    va_start(args, format);

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    while (format[i] != '\0')
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            int j = 13;
            while (j <= 13)
            {
                if (conversion[j].id[0] == format[i] && conversion[j].id[1] == format[i + 1])
                {
                    len += conversion[j].f(args);
                    i += 2;
                    break;  // exit the inner loop when a specifier is found
                }
                j--;
            }
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

