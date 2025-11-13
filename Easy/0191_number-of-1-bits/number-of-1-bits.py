#!/bin/python3

from typing import List

class Solution:
    def hammingWeight(self, n: int) -> int:
        count : int = 0
        while n > 0 :
            count += n & 1
            n >>= 1
        return count

def main():
    tests : List[int] = [
        11,
        128,
        2147483645,
        0,
    ]

    for n in tests:
        print(f"---\nN: {n} hammingWeight: {Solution().hammingWeight(n)}")

if __name__ == "__main__":
    main()
