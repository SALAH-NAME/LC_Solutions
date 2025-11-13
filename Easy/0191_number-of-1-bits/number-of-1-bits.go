package main

import (
	"fmt"
)

func hammingWeight(n int) int {
	count := 0
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
}

func main() {
	tests := []int{
		11,
		128,
		2147483645,
		0,
	}

	for _, n := range tests {
		fmt.Printf("---\nN: %d hammingWeight: %d\n", n, hammingWeight(n))
	}
}
