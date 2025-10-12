#!/bin/python3

from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        i: int = 0
        for j in range(1, len(nums)):
            if nums[j] != nums[i]:
                i += 1
                nums[i] = nums[j]
        return i + 1

def main():
    tests : List[List[int]] = [
        [0,0,1,1,1,2,2,3,3,4],
        [1,1,2],
        [1,1,2,4,4,7,7],
    ]
    
    for t in tests:
        print("---")
        print("Origin:> ", t, "\nDuplicates:> ", Solution().removeDuplicates(t), "\nResult:> ", t)

if __name__ == "__main__":
    main()
