#include "main.h"

/**
 * printf_string - Custom printf function for string specifier
 * @val: va_list containing the argument
 *
 * Return: The number of characters printed (excluding null byte)
 */
int printf_string(va_list val)
{
	char *str = "";
	int len = 0;

	str = va_arg(val, char *);

	if (str == NULL)
	{
		str = "(null)";
		write(1, str, _strlen(str));
		len = _strlen(str);
		return (len);
	}
	else
	{
		write(1, str, _strlen(str));
		len = _strlen(str);
		return (len);
	}
}

