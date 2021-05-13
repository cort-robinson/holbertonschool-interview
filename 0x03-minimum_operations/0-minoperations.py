#!/usr/bin/python3
"""def minOperations(n)"""


def minOperations(n):
    """Determine min operations"""
    ans = 0
    d = 2

    while n > 1:
        while n % d == 0:
            ans += d
            n /= d
        d += 1
    return ans
