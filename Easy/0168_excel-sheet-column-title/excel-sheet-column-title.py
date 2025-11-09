#!/bin/python3

from typing import List

class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        result = ""
        while columnNumber > 0:
            columnNumber -= 1
            result = chr(ord('A') + columnNumber % 26) + result
            columnNumber //= 26
        return result

def main():
    tests : List[int] = [
        1,
        28,
        701,
    ]
    for n in tests:
        print(f"---\nNumber: {n} Title: {Solution().convertToTitle(n)}")

if __name__ == "__main__":
    main()
