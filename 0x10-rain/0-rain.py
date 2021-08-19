#!/usr/bin/python3
"""Module to find the rain
"""


def rain(walls):
    """Given a list of non-negative integers representing the heights of walls
    with unit width 1, as if viewing the cross-section of a relief map,
    calculate how many square units of water will be retained after it rains.
    """
    left = 0
    right = len(walls) - 1
    l_max = 0
    r_max = 0
    rainwater = 0

    while (left <= right):
        if r_max <= l_max:
            rainwater += max(0, r_max - walls[right])
            r_max = max(r_max, walls[right])
            right -= 1
        else:
            rainwater += max(0, l_max - walls[left])
            l_max = max(l_max, walls[left])
            left += 1
    return rainwater
