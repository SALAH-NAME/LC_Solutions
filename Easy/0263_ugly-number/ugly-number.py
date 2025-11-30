#!/bin/python3

from typing import List

class Solution:
    def isUgly(self, n: int) -> bool:
        if n <= 2:
            return False
        for p in [2, 3, 5]:
            while n % p == 0:
                n //= p
        return n == 1

def main():
    tests: List[int] = [
        6,
        1,
        14,
    ]

    for n in tests:
        print(f"---\nn= {n}\nisUgly: {Solution().isUgly(n)}")

if __name__ == "__main__":
    main()
