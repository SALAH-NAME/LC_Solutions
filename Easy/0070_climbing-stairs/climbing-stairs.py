#!/bin/python3

from typing import List

class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1
        prev2, prev1 = 1, 1
        for _ in range(2, n + 1):
            prev2, prev1 = prev1, prev1 + prev2
        return prev1

def main():
    tests: List[int] = [
        2,
        3,
        45
    ]

    for n in tests:
        print(f"---\nn= {n} => climbStairs: {Solution().climbStairs(n)}")

if __name__ == "__main__":
    main()
