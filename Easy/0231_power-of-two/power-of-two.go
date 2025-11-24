package main

import (
	"fmt"
)

func isPowerOfTwo(n int) bool {
  return n > 0 && (n & (n - 1)) == 0
}

func main() {
	tests := []int{
		1,
		16,
		3,
		0,
	}

	for _, n := range tests {
		fmt.Printf("---\nn: %d\nisPowerOfTwo: %t\n", n, isPowerOfTwo(n))
	}
}
