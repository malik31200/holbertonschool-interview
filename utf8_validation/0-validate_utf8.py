#!/usr/bin/python3
"""
UTF-8 validation
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
        data: list of integers representing bytes

    Returns:
        True if data is a valid UTF-8 encoding, False otherwise
    """
    bytes_to_follow = 0

    for num in data:
        # Only consider the 8 least significant bits
        byte = num & 0xFF

        if bytes_to_follow == 0:
            # 1-byte character (0xxxxxxx)
            if (byte >> 7) == 0:
                continue

            # 2-byte character (110xxxxx)
            elif (byte >> 5) == 0b110:
                bytes_to_follow = 1

            # 3-byte character (1110xxxx)
            elif (byte >> 4) == 0b1110:
                bytes_to_follow = 2

            # 4-byte character (11110xxx)
            elif (byte >> 3) == 0b11110:
                bytes_to_follow = 3

            else:
                return False

        else:
            # Following bytes must start with 10xxxxxx
            if (byte >> 6) != 0b10:
                return False

            bytes_to_follow -= 1

    # All characters must be completed
    return bytes_to_follow == 0
