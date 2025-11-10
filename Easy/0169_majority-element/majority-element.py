#!/bin/python3

from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate

def main():
    tests : List[List[int]] = [
        [3,2,3],
        [2,2,1,1,1,2,2],
    ]
    for nums in tests:
        print(f"---\nnums: {nums}")
        print(f"majorityElement: {Solution().majorityElement(nums)}")

if __name__ == "__main__":
    main()
