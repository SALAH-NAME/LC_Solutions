#!/bin/python3

from typing import List
from dataclasses import dataclass

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i, j, k = m - 1, n - 1, m + n - 1
        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1

@dataclass
class TestCase:
    nums1: List[int]
    m: int
    nums2: List[int]
    n: int

def main():
    tests: List[TestCase]= [
        TestCase([1,2,3,0,0,0], 3, [2,5,6], 3),
        TestCase([1], 1, [], 0),
        TestCase([0], 0, [1], 1),
    ]

    for tc in tests:
        print(f"---\nums1= {tc.nums1} m= {tc.m} nums2= {tc.nums2} n= {tc.n}")
        Solution().merge(tc.nums1, tc.m, tc.nums2, tc.n)
        print(f"merge= {tc.nums1}")

if __name__ == "__main__":
    main()
