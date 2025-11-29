#!/bin/python3

from typing import List

class Solution:
    def addDigits(self, num: int) -> int:
        if num == 0:
            return 0
        return 1 + (num - 1) % 9

def main():
    tests: List[int] = [
        38,
        0,
    ]

    for n in tests:
        print(f"---\nnum: {n}\naddDigits: {Solution().addDigits(n)}")

if __name__ == "__main__":
    main()
