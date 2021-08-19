#!/usr/bin/python3
"""Module to find the rain
"""


def rain(walls) -> int:
    """
    Given a list of non-negative integers representing the heights of walls
    with unit width 1, as if viewing the cross-section of a relief map,
    calculate how many square units of water will be retained after it rains.

    * Prototype: def rain(walls)
    * walls is a list of non-negative integers.
    * Return: Integer indicating total amount of rainwater retained.
    * Assume that the ends of the list (before index 0 and after index
      walls[-1]) are not walls, meaning they will not retain water.
    * If the list is empty return 0.
    """
    if len(walls) == 0:
        return 0
    rainwater = 0
    for i in range(len(walls)-2):
        if walls[i] > walls[i+1]:
            rainwater += (walls[i] - walls[i+1])
    return rainwater
