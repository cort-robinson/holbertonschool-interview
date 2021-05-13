#!/usr/bin/python3
"""def minOperations(n)"""


def minOperations(n):
    """Determine min operations"""
    result = 0

    for i in range(2, n+1):
        while n % i == 0:
            result += i
            n = n/i

    return result
