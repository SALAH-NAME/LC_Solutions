#!/bin/python3

from typing import List

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        row: List[int] = [0] * (rowIndex + 1)
        row[0] = 1
        for i in range(1, rowIndex + 1):
            for j in range(i, 0, -1):
                row[j] += row[j - 1]
        return row

def main():
    tests: List[int] = [
        3,
        0,
        1,
    ]

    for n in tests:
        print(f"---\nn: {n}\nRow: {Solution().getRow(n)}")

if __name__ == "__main__":
    main()
