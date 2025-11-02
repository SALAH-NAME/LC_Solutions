#/bin/python3

from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = prices[0]
        maxProfit = 0

        for price in prices:
            if price < minPrice:
                minPrice = price
            elif maxProfit < price - minPrice:
                maxProfit = price - minPrice
        return maxProfit

def main():
    tests: List[List[int]] = [
        [7,1,5,3,6,4],
        [7,6,4,3,1],
    ]

    for prices in tests:
        print(f"---\nprices: {prices}")
        print(f"maxProfit: {Solution().maxProfit(prices)}")

if __name__ == "__main__":
    main()
