#!/usr/bin/python3
"""Module to find the rain
"""


def find_gap(start_index, walls):
    """Measure horizontal gap between current wall and next wall
    Return tuple (gap size, size of shorter wall), or none if no next wall
    """
    gap = 0
    for col in range(start_index + 1, len(walls)):
        if walls[col] > 0:
            return (gap, min(walls[start_index], walls[col]))
        gap += 1


def rain(walls):
    """Given a list of non-negative integers representing the heights of walls
    with unit width 1, as if viewing the cross-section of a relief map,
    calculate how many square units of water will be retained after it rains.
    """
    if len(walls) == 0:
        return 0
    rainwater = 0
    for i in range(len(walls) - 1):
        if walls[i] > walls[i + 1]:
            gap_info = find_gap(i, walls)
            if not gap_info:
                break
            gap = gap_info[0]
            small_wall = gap_info[1]
            rainwater += (small_wall * gap)
    return rainwater
