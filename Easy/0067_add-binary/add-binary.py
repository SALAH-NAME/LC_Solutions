#!/bin/python3

from typing import List, Dict

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2))[2:]

def main():
    tests: List[Dict[str, str]] = [
        {"a": "11", "b": "1"},
        {"a": "1010", "b": "1011"},
        {"a": "1011111", "b": "1"},
    ]

    for tc in tests:
        print(f'a="{tc["a"]}" b="{tc["b"]}" => {Solution().addBinary(tc["a"], tc["b"])}')

if __name__ == "__main__":
    main()
