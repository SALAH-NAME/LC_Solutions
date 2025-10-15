#!/bin/python3

from typing import List, Tuple

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left : int = 0
        right : int = len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif (nums[mid] > target):
                right = mid - 1
            else:
                left = mid + 1
        return left

def main():
    tests : List[Tuple[List[int], int]] = [
        ([1,3,5,6], 5),
        ([1,3,5,6], 2),
        ([1,3,5,6], 7),
    ]

    for arr, target in tests:
        print("---\nnums= ", arr, "\ntarget= ", target, "\nres= ", Solution().searchInsert(arr, target))

if __name__ == "__main__":
    main()
