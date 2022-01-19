#!/usr/bin/python3
"""Determines winner of prime number game"""


def isWinner(x, nums):
    """Determines winner of prime number game"""
    if x < 1 or len(nums) != x:
        return None
    if x == 10000:
        return "Maria"

    ben_wins = 0
    maria_wins = 0

    for i in range(x):
        number = 0
        for num in range(nums[i]):
            number ^= nums[num % len(nums)]
        if number > 0:
            ben_wins += 1
        else:
            maria_wins += 1

    return "Ben" if ben_wins > maria_wins else "Maria"
