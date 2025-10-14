#!/bin/python3

from typing import List, Tuple

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        for j in range(len(nums)):
            if nums[j] != val:
                nums[i] = nums[j]
                i += 1
        return i

def main() -> None :
    tests: List[Tuple[List[int], int]] = [
        ([3,2,2,3],3),
        ([0,1,2,2,3,0,4,2],2),
        ([3],3),
    ]

    for arr, val in tests:
        print("---\narr: ", arr, "\nval: ", val)
        val = Solution().removeElement(arr,val)
        print("--after_solution--", "\nres: ", val)
        print("resArr: ", arr[:val])

if __name__ == "__main__":
    main()
