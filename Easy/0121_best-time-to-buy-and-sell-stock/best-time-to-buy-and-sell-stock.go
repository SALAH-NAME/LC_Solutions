package main

import (
	"fmt"
)

func maxProfit(prices []int) int {
	minPrice := prices[0]
	maxProfit := 0

	for _, price := range prices {
		if price < minPrice {
			minPrice = price
		} else if maxProfit < price - minPrice {
			maxProfit = price - minPrice
		}
	}
	return maxProfit
}

func main() {
	tests := [][]int{
		{7,1,5,3,6,4},
		{7,6,4,3,1},
	}

	for _, prices := range tests {
		fmt.Printf("---\nprices: %v\n", prices)
		fmt.Printf("maxProfit: %d\n", maxProfit(prices))
	}
}
