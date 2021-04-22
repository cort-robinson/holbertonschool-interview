#!/usr/bin/python3
"""
You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """Determines if all boxes can be opened"""
    if not boxes:
        return False
    index = 0
    keys = {0}
    valid_keys = set(range(len(boxes)))

    while index < len(keys):
        index = len(keys)
        result = []
        for key in keys:
            if boxes[key]:
                result.extend(boxes[key])
        keys = keys | set(result)
        keys = keys & valid_keys
        if len(keys) == len(boxes):
            return True
    return False
