#include "main.h"
/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    int len = 0;
    char *str;
    char ch;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '\0')
            return (-1);

        if (*format != '%')
        {
            _putchar(*format);
            len++;
            format++;
        }
        else
        {
            format++;
            switch (*format)
            {
            case 'c':
                ch = va_arg(args, int);
                if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
                    return (-1);
                _putchar(ch);
                len++;
                break;
            case 's':
                str = va_arg(args, char *);
                if (str == NULL)
                {
                    str = "(null)";
                    write(1, str, _strlen(str));
                    len += _strlen(str);
                }
                else
                {
                    write(1, str, _strlen(str));
                    len += _strlen(str);
                }
                break;
            case '%':
                _putchar('%');
                len++;
                break;
            case '\0':
                return (-1);
            default:
                _putchar('%');
                _putchar(*format);
                len += 2;
                break;
            }
            format++;
        }
    }

    va_end(args);
    return (len);
}

