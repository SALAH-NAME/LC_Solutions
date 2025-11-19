#!/bin/python3

from typing import List
from dataclasses import dataclass

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        seen = {}
        for i, num in enumerate(nums):
            if num in seen and i - seen[num] <= k:
                return True
            seen[num] = i
        return False

@dataclass
class TestCase:
    nums : List[int]
    k : int

def main():
    tests : List[TestCase] = [
        TestCase([1,2,3,1], 3),
        TestCase([1,0,1,1], 1),
        TestCase([1,2,3,1,2,3], 2),
    ]

    for tc in tests:
        print(f"---\nnums: {tc.nums} k: {tc.k}")
        print(f"containsNearbyDuplicate: {Solution().containsNearbyDuplicate(tc.nums, tc.k)}")

if __name__ == "__main__":
    main()
