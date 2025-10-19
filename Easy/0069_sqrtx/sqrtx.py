#!/bin/python3

from typing import List

class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0
        r = x
        while r * r > x:
            r = (r + x // r) // 2
        return r

def main():
    tests: List[int] = [
        4,
        8,
        16,
        0,
    ]

    for x in tests:
        print(f"---\nx= {x} => Sqrt= {Solution().mySqrt(x)}")

if __name__ == "__main__":
    main()
