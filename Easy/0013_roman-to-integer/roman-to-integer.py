#!/bin/python3

class Solution:
    def romanToInt(self, s: str) -> int:
        roman: dict[str, int] = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
        }
        total: int = 0
        last: int = 0
        for ch in reversed(s):
            value = roman[ch]
            if value >= last:
                total += value
            else:
                total -= value
            last = value
        return total

def main():
    tests: [str] = ["III", "LVIII","MCMXCIV"]
    for t in tests:
        print(t,": ", Solution().romanToInt(t))

if __name__ == "__main__":
    main()
