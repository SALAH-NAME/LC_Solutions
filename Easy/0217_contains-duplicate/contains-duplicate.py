#!/bin/python3

from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = set(nums)
        if len(nums) == len(seen):
            return False
        return True

def main():
    tests: List[List[int]] = [
        [1,2,3,1],
        [1,2,3,4],
        [1,1,1,3,3,4,3,2,4,2],
    ]

    for nums in tests:
        print(f"---\nnums= {nums}")
        print(f"containsDuplicate: {Solution().containsDuplicate(nums)}")

if __name__ == "__main__":
    main()
