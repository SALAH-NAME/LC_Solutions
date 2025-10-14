#!/bin/python3

from typing import List, Tuple

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)

def main():
    tests : List[Tuple[str, str]] = [
        ("sadbutsad", "sad"),
        ("leetcode", "leeto"),
    ]

    for haystack, needle in tests:
        print("---\nhaystack: ", haystack, "\nneedle: ", needle, "\nstrStr: ", Solution().strStr(haystack, needle))

if __name__ == "__main__":
    main()
