#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned integer is a palindrome
 *
 * @n: number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long divisor = 1;
	unsigned long left;
	unsigned long right;

	/* Find the highest power of 10 */
	while (n / divisor >= 10)
		divisor *= 10;

	while (n != 0)
	{
		/* Get first and last digits */
		left = n / divisor;
		right = n % 10;

		/* Compare them */
		if (left != right)
			return (0);

		/*
		 * Remove first and last digits:
		 * Example: 12321 -> 232
		 */
		n = (n % divisor) / 10;

		/* Update divisor (remove two digits) */
		divisor /= 100;
	}

	return (1);
}
