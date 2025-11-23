#!/bin/python3

from typing import List

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        res = []
        n = len(nums)
        i = 0
        while i < n:
            start = nums[i]
            while i + 1 < n and nums[i + 1] == nums[i] + 1:
                i += 1
            end = nums[i]
            if start == end:
                res.append(str(start))
            else:
                res.append(f"{start}->{end}")
            i += 1
        return res

def main():
    tests : List[List[int]] = [
        [0,1,2,4,5,7],
        [0,2,3,4,6,8,9],
    ]

    for nums in tests:
        print(f"---\nnums: {nums}")
        print(f"summaryRanges: {Solution().summaryRanges(nums)}")

if __name__ == "__main__":
    main()
