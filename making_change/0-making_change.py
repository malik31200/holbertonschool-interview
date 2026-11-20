#!/usr/bin/python3
"""Coin change module."""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given total.

    Args:
        coins (list): Values of the coins in possession.
        total (int): Target amount.

    Returns:
        int: Fewest number of coins needed, 0 if total <= 0, -1 if impossible.
    """
    if total <= 0:
        return 0

    dp = [total + 1] * (total + 1)
    dp[0] = 0

    for amount in range(1, total + 1):
        for coin in coins:
            if coin <= amount:
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    if dp[total] > total:
        return -1
    return dp[total]
