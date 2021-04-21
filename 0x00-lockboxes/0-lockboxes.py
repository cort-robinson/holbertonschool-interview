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
    keys = list(set(boxes[0]))
    added = True
    numboxes = len(boxes)
    emptyboxes = 0

    if 0 not in keys:
        keys.append(0)

    if not boxes[0] and numboxes < 2:
        return True

    while added:
        added = False
        remaining = keys[index:]
        result = []
        for key in remaining:
            try:
                result += boxes[key]
            except Exception:
                pass
        for key in result:
            if key not in keys and key < numboxes:
                keys.append(key)
                index += 1
                added = True

    return len(keys) == numboxes
