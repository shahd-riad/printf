#include "main.h"

/**
 * printf_bin - Custom printf function for binary integers
 * @val: The va_list containing the binary integer to print
 *
 * Return: The number of characters printed
 */
int printf_bin(va_list val)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	n = va_arg(val,  unsigned int);
	m = 2147483648U; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);

			count++;
		}
	}
	return (count);
}
