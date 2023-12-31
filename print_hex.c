#include "main.h"

/**
 * printf_hex_gen - Custom printf function for hexadecimal conversion
 * @val: The va_list containing the unsigned integer to print
 * @uppercase: Flag to determine if the output should be uppercase
 *
 * Return: The number of characters printed
 */
int printf_hex_gen(va_list val, int uppercase)
{
	char hex[32];
	int index = 0, count = 0, i;
	char upper[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	char lower[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	unsigned int num = va_arg(val, unsigned int);

	if (num == 0)
	{
		_putchar('0');
		count++;
		return (count);
	}

	while (num > 0)
	{
		int remainder = num % 16;

		if ((remainder < 10))
			hex[index++]  = remainder + '0';
		else if ((remainder >= 10) && uppercase == 1)
			hex[index++] = upper[remainder - 10];
		else
			hex[index++] = lower[remainder - 10];
		num /= 16;
	}

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(hex[i]);
		count++;
	}

	return (count);
}

/**
 * printf_hex - Custom printf function for lowercase hexadecimal conversion
 * @val: The va_list containing the unsigned integer to print
 *
 * Return: The number of characters printed
 */
int printf_hex(va_list val)
{
	return (printf_hex_gen(val, 0));
}

/**
 * printf_HEX - Custom printf function for uppercase
 * hexadecimal conversion
 * @val: The va_list containing the unsigned integer to print
 *
 * Return: The number of characters printed
 */
int printf_HEX(va_list val)
{
	return (printf_hex_gen(val, 1));
}

/**
 * printf_HEX_aux - prints an hexgecimal number.
 * @num: number to print.
 * Return: counter.
 */
int printf_HEX_aux(unsigned int num)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}
