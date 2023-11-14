#include "main.h"

/**
 * printf_percent - Custom printf function for percent symbol
 * @val: The va_list (not used in this function)
 *
 * Return: The number of characters printed (always 1)
 */

int printf_perc(va_list val)
{
	(void)val; /* Unused parameter, silence the warning */
	_putchar('%');
	return (1);
}

