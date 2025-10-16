#!/bin/python3

from typing import List

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        len: int = 0
        s = s.rstrip()
        for c in reversed(s):
            if (c.isspace()):
                break
            len += 1
        return len

# def lengthOfLastWord(s: str) -> int:
#     return len(s.split()[-1])

def main():
    tests: List[str] = [
        "Hello World",
        "   fly me   to   the moon  ",
        "luffy is still joyboy",
    ]

    for t in tests:
        print("---\ns=\"", t, "\" => len=", Solution().lengthOfLastWord(t))

if __name__ == "__main__":
    main()
