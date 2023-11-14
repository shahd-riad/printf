#include "main.h"

/**
 * printf_oct - Custom printf function for octal conversion
 * @val: The va_list containing the unsigned integer to print
 *
 * Return: The number of characters printed
 */
int printf_oct(va_list val)
{
	char oct[32];
	int index = 0, count = 0, i;
	unsigned int num = va_arg(val, unsigned int);

	if (num == 0)
	{
		_putchar('0');
		count++;
		return (count);
	}

	while (num > 0)
	{
		oct[index++] = num % 8;
		num /= 8;
	}

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(oct[i] + '0');
		count++;
	}

	return (count);
}

