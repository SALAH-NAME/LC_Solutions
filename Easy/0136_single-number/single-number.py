#!/bin/python3

from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans: int = 0
        for n in nums:
            ans ^= n
        return ans

def main():
    tests: List[List[int]] = [
        [2,2,1],
        [4,1,2,1,2],
        [1],
    ]

    for nums in tests:
        print(f"---\nnums: {nums}\nsingleNumber: {Solution().singleNumber(nums)}")

if __name__ == "__main__":
    main()
