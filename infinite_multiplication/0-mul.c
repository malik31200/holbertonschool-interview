#include "holberton.h"
#include <stdlib.h>

/**
 * string_length - Calculates the length of a string.
 * @str: The string to measure.
 *
 * Return: The length of the string.
 */
static unsigned int string_length(char *str)
{
	unsigned int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * is_digit_string - Checks whether a string contains only digits.
 * @str: The string to check.
 *
 * Return: 1 if valid, otherwise 0.
 */
static int is_digit_string(char *str)
{
	unsigned int i;

	if (str[0] == '\0')
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * print_error - Prints Error and exits with status 98.
 */
static void print_error(void)
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
 * multiply - Multiplies two positive integers of arbitrary length.
 * @num1: First number as a string.
 * @num2: Second number as a string.
 *
 * Return: Pointer to the result string, or NULL on failure.
 */
static char *multiply(char *num1, char *num2)
{
	unsigned int len1, len2, total, i, j, pos;
	int product, carry;
	char *result;

	len1 = string_length(num1);
	len2 = string_length(num2);
	total = len1 + len2;

	result = malloc(total + 1);
	if (result == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		result[i] = 0;
	result[total] = '\0';

	for (i = len1; i > 0; i--)
	{
		carry = 0;

		for (j = len2; j > 0; j--)
		{
			pos = i + j - 1;
			product = (num1[i - 1] - '0') *
				(num2[j - 1] - '0') + result[pos] + carry;

			result[pos] = product % 10;
			carry = product / 10;
		}

		result[i - 1] += carry;
	}

	pos = 0;
	while (pos < total - 1 && result[pos] == 0)
		pos++;

	for (i = pos; i < total; i++)
		result[i] += '0';

	return (result);
}

/**
 * main - Multiplies two positive numbers.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, or 98 on error.
 */
int main(int argc, char **argv)
{
	char *result;
	unsigned int i;

	if (argc != 3)
		print_error();

	if (!is_digit_string(argv[1]) || !is_digit_string(argv[2]))
		print_error();

	result = multiply(argv[1], argv[2]);
	if (result == NULL)
		print_error();

	i = 0;
	while (result[i] != '\0')
	{
		_putchar(result[i]);
		i++;
	}
	_putchar('\n');

	free(result);
	return (0);
}
