#include "main.h"

/**
 * printf_char - Custom printf function for character specifier
 * @val: va_list containing the argument
 *
 * Return: The number of characters printed (excluding null byte)
 */
int printf_char(va_list val)
{
    char ch;
    
    ch = va_arg(val, int);

    if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
        return (-1);

    _putchar(ch);
    return (1);
}

