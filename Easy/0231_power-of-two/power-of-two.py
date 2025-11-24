#!/bin/python3

from typing import List

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and (n & (n - 1)) == 0

def main():
    tests: List[int] = [
        1,
        16,
        3,
        0,
    ]

    for n in tests:
        print(f"---\nn: {n}\nisPowerOfTwo: {Solution().isPowerOfTwo(n)}")

if __name__ == "__main__":
    main()
