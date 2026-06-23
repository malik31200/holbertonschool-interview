#!/usr/bin/python3
"""
Minimum operations to reach n characters using Copy All and Paste
"""


def minOperations(n):
    """
    Returns the minimum number of operations needed
    to get exactly n 'H' characters.
    If impossible, return 0.
    """
    if n <= 1:
        return 0

    ops = 0
    i = 2

    while i * i <= n:
        while n % i == 0:
            ops += i
            n //= i
        i += 1

    if n > 1:
        ops += n

    return ops
