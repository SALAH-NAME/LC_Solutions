#!/bin/python3

from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle: List[List[int]] = [[1]]

        for _ in range(1, numRows):
            prev = triangle[-1]
            row = [1] + [prev[i] + prev[i+1] for i in range(len(prev)-1)] + [1]
            triangle.append(row)
        return triangle


def main():
    tests: List[int]=[
        5,
        1
    ]

    for rows in tests:
        print(f"---\nnumRows: {rows}\nTriangle: {Solution().generate(rows)}")

if __name__ == "__main__":
    main()
