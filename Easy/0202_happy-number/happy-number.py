#!/bin/python3

from typing import List

class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        while n != 1 and n not in seen:
            seen.add(n)
            n = sum(int(digit) ** 2 for digit in str(n))
        return n == 1

def main():
    tests : List[int] = [
        19,
        2,
        1,
        10,
        42,
        2147483647,
    ]

    for n in tests:
        print(f"---\nN: {n} isHappy: {Solution().isHappy(n)}")

if __name__ == "__main__":
    main()
