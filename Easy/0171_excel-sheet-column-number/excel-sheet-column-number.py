#!/bin/python3

from typing import List

class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        res : int = 0
        for c in columnTitle:
            res = res * 26 + (ord(c) - ord('A') + 1)
        return res

def main():
    tests : List[str] = [
        "A",
        "AB",
        "ZY"
    ]
    for t in tests:
        print(f"---\ntitle: '{t}' number: {Solution().titleToNumber(t)}")

if __name__ == "__main__":
    main()
