#include "main.h"

/**
 * printf_int - Custom printf function for integers
 * @args: The va_list containing the integer to print
 *
 * Return: The number of characters printed
 */
int printf_int(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit, exp = 1;
	int i = 1;

	n = n / 10;
	num = n;

	if (n < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}

	while (n > 0)
	{
		digit = n % 10;
		num = num * 10 + digit;
		n = n / 10;
		exp *= 10;
	}

	while (exp > 1)
	{
		digit = num / exp;
		_putchar(digit + '0');
		num %= exp;
		exp /= 10;
		i++;
	}

	return (i);
}

/**
 * printf_dec - Custom printf function for decimal integers
 * @args: The va_list containing the decimal integer to print
 *
 * Return: The number of characters printed
 */
int printf_dec(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit, exp = 1;
	int i = 1;

	n = n / 10;
	num = n;

	if (n < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}

	while (n > 0)
	{
		digit = n % 10;
		num = num * 10 + digit;
		n = n / 10;
		exp *= 10;
	}

	while (exp > 1)
	{
		digit = num / exp;
		_putchar(digit + '0');
		num %= exp;
		exp /= 10;
		i++;
	}

	return (i);
}
