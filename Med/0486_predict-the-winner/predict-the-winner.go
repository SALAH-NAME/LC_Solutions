package main

import (
	"fmt"
)

func predictTheWinner(nums []int) bool {
	n := len(nums)
	dp := make([][]int, n)

	for i := range dp {
		dp[i] = make([]int, n)
		dp[i][i] = nums[i]
	}

	for length := 2; length <= n; length++ {
		for i := 0; i+length-1 < n; i++ {
			j := i + length - 1
			takeLeft := nums[i] - dp[i+1][j]
			takeRight := nums[j] - dp[i][j-1]
			dp[i][j] = max(takeLeft, takeRight)
		}
	}
	return dp[0][n-1] >= 0
}

func main() {
	tests := [][]int{
		{1, 5, 2},
		{1, 5, 233, 7},
	}

	for _, t := range tests {
		fmt.Printf("---\nnums: %v\n", t)
		fmt.Printf("predictTheWinner: %t\n", predictTheWinner(t))
	}
}
