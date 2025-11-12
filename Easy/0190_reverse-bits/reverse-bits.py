#!/bin/python3

from typing import List

class Solution:
    def reverseBits(self, n: int) -> int:
        rev : int = 0
        for i in range(32):
            rev = (rev << 1) | (n & 1)
            n >>= 1
        return rev

def main():
    tests : List[int] = [
        43261596,
        2147483644,
        0,
        1,
    ]
    for n in tests:
        print(f"---\nN: {n}\nreverseBits: {Solution().reverseBits(n)}")

if __name__ == "__main__":
    main()
