#!/bin/python3

from typing import List
from collections import Counter
from dataclasses import dataclass

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)

@dataclass
class TestCase:
    s: str
    t: str

def main():
    tests: List[TestCase] = [
        TestCase("anagram", "nagaram"),
        TestCase("rat", "car"),
    ]

    for tc in tests:
        print(f"---\ns: '{tc.s}', t: '{tc.t}'")
        print(f"isAnagram: {Solution().isAnagram(tc.s, tc.t)}")

if __name__ == "__main__":
    main()
