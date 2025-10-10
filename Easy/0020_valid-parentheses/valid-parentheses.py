#!/bin/python3

class Solution:
    def isValid(self, s: str) -> bool:
        pair : dict[str, str] = {
            ')': '(',
            '}': '{',
            ']': '[',
        }
        stack = []
        for c in s:
            if c in "({[":
                stack.append(c)
            elif not stack or stack.pop() != pair[c]:
                    return False
        return not stack


def main():
    tests : list[str] = {
        "()",
        "()[]{}",
        "(]",
        "([])",
        "([)]"
    }

    for t in tests:
        print(t,"=> ", Solution().isValid(t))

if __name__ == "__main__":
    main()
