#!/usr/bin/python3
"""
Function that Determine if all the boxes can be opened
Each box can contain keys that open other boxes.
The first box (box 0) is already unlocked.
The function returns True if all boxes can be opened;
otherwise, it returns False.
"""
def canUnlockAll(boxes):
    # We create a set to keep the opened boxes
    opened = set([0]) # The box 0 is opening at start
    keys = [0] # We start with the key of the box 0

    # While there are keys to explore
    while keys:
        current = keys.pop() # we take the last box added

        # we look all the keys find in the current box
        for key in boxes[current]:
            # If the key corresponds to a real box and it hasn't been opened yet
            if  key < len(boxes) and key not in opened:
                opened.add(key) # we open the box
                keys.append(key) # we add this box to explore later

    # If all the boxes are opened, return True, otherwise False
    return len(opened) == len(boxes)
