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
	int index = 0;
	unsigned int num = va_arg(val, unsigned int);

	if (num == 0)
	{
		putchar('0');
		index++;
		return (index);
	}

	while (num > 0)
	{
		binary[index++] = num % 2 + '0';
		num /= 2;
	}

	for (int i = index - 1; i >= 0; i--)
	{
		putchar(binary[i]);
	}

	return (index);
}

