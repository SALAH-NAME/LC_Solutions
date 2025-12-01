#!/bin/python3

from typing import List

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        expected = n * (n + 1) // 2
        actual = sum(nums)
        return expected - actual

def main():
    tests: List[List[int]] = [
        [3,0,1],
        [0,1],
        [9,6,4,2,3,5,7,0,1],
    ]

    for nums in tests:
        print(f"---\nnums: {nums}")
        print(f"missingNumber: {Solution().missingNumber(nums)}")

if __name__ == "__main__":
    main()
