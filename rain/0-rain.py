#!/usr/bin/python3
"""Calculate the amount of rainwater retained between walls."""


def rain(walls):
    """Return the total amount of rainwater retained by the walls.

    Args:
        walls: A list of non-negative integers representing wall heights.

    Returns:
        The total number of square units of retained rainwater.
    """
    if not walls:
        return 0

    left = 0
    right = len(walls) - 1
    left_max = 0
    right_max = 0
    water = 0

    while left < right:
        if walls[left] <= walls[right]:
            if walls[left] >= left_max:
                left_max = walls[left]
            else:
                water += left_max - walls[left]
            left += 1
        else:
            if walls[right] >= right_max:
                right_max = walls[right]
            else:
                water += right_max - walls[right]
            right -= 1

    return water
