#!/bin/python3

from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix : str = ""
        for i in range(len(strs[0])):
            c = strs[0][i]
            for s in strs:
                if i >= len(s) or c != s[i]:
                    return prefix
            prefix += c
        return prefix


def main():
    tests: List[List[str]] = [
        ["flower", "flow", "flight"],
        ["dog", "racecar", "car"],
        ["a"]
    ]
    for t in tests:
        print(t, "=>", Solution().longestCommonPrefix(t))

if __name__ == "__main__":
    main()
