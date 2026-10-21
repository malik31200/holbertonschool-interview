
#include "holberton.h"
#include <stdlib.h>

/**
 * string_length - Returns the length of a string.
 * @s: String to measure.
 *
 * Return: String length.
 */
static unsigned int string_length(char *s)
{
	unsigned int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * is_digits - Checks whether a string contains only digits.
 * @s: String to check.
 *
 * Return: 1 if valid, 0 otherwise.
 */
static int is_digits(char *s)
{
	unsigned int i;

	if (s[0] == '\0')
		return (0);

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * error - Prints Error and exits with status 98.
 */
static void error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * multiply - Multiplies two arbitrarily large positive integers.
 * @a: First number.
 * @b: Second number.
 *
 * Return: Allocated result string, or NULL on allocation failure.
 */
static char *multiply(char *a, char *b)
{
	unsigned int la, lb, len, i, j, k;
	int *digits;
	char *result;
	int carry, product;

	la = string_length(a);
	lb = string_length(b);
	len = la + lb;
	digits = malloc(sizeof(int) * len);
	if (digits == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		digits[i] = 0;
	for (i = la; i > 0; i--)
	{
		carry = 0;
		for (j = lb; j > 0; j--)
		{
			k = i + j - 1;
			product = (a[i - 1] - '0') * (b[j - 1] - '0');
			product += digits[k] + carry;
			digits[k] = product % 10;
			carry = product / 10;
		}
		digits[i - 1] += carry;
	}
	i = 0;
	while (i < len - 1 && digits[i] == 0)
		i++;
	result = malloc(len - i + 1);
	if (result == NULL)
	{
		free(digits);
		return (NULL);
	}
	for (j = 0; i < len; i++, j++)
		result[j] = digits[i] + '0';
	result[j] = '\0';
	free(digits);
	return (result);
}
/**
 * main - Multiplies two positive integers.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char **argv)
{
	char *result;
	unsigned int i;

	if (argc != 3)
		error();

	if (!is_digits(argv[1]) || !is_digits(argv[2]))
		error();

	result = multiply(argv[1], argv[2]);
	if (result == NULL)
		error();

	for (i = 0; result[i] != '\0'; i++)
		_putchar(result[i]);

	_putchar('\n');
	free(result);
	return (0);
}

