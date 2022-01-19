#!/usr/bin/python3
"""Determines winner of prime number game"""


def isWinner(x, nums):
    """Determines winner of prime number game"""
    if x < 1 or len(nums) < 1:
        return None
    number = 0
    for i in range(len(nums)):
        number ^= nums[i % len(nums)]

    return "Ben" if number > 0 else "Maria"
