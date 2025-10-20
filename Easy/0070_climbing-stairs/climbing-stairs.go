package main

import (
	"fmt"
)

func climbStairs(n int) int {
	if n< 2 {
		return 1
	}
	prev2, prev1 := 1, 1
	for i := 2; i <= n; i++ {
		prev2, prev1 = prev1, prev1 + prev2
	}
	return prev1
}

func main() {
	tests := []int{
		2,
		3,
		45,
	}

	for _, n := range tests {
		fmt.Printf("---\nn= %d => climbStairs: %d\n", n, climbStairs(n))
	}
}
