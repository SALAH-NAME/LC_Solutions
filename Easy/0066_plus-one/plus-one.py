#!/bin/python3

from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry: int = 1
        for i in range(len(digits) - 1, -1, -1):
            digits[i] += carry
            if digits[i] < 10:
                return digits
            digits[i] = 0
            carry = 1
        if carry == 1:
            digits.insert(0,1)
        return digits

def main():
    tests: List[List[int]] = [
        [1,2,3],
        [4,3,2,1],
        [9],
        [9, 9, 9, 9],
    ]

    for arr in tests:
        print("---\ndigits: ", arr)
        print("plusOne: ", Solution().plusOne(arr))

if __name__ == "__main__":
    main()
