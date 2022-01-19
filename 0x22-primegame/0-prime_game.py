#!/usr/bin/python3
"""Determines winner of prime number game"""


def isWinner(x, nums):
    """Determines winner of prime number game"""
    if x < 1 or len(nums) < 1:
        return "none"
    number = 0
    for i in range(len(nums)):
        number ^= nums[i % len(nums)]

    print(number)

    return "Ben" if number > 0 else "Maria"
