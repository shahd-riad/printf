#include "main.h"

/**
 * printf_bin - Custom printf function for binary integers
 * @val: The va_list containing the binary integer to print
 *
 * Return: The number of characters printed
 */
int printf_bin(va_list val)
{
	char binary[32];
	int index = 0, count = 0;
	int i;
	unsigned int num = va_arg(val, unsigned int);

	if (num == 0)
	{
		_putchar('0');
		count++;
		return (count);
	}

	while (num > 0)
	{
		binary[index++] = num % 2;
		num /= 2;
	}

	if (index > 32)
		return (-1);

	for (i = index - 1; i >= 0; i--)
	{
		putchar(binary[i] + '0');
		count++;
	}

	return (count);
}

