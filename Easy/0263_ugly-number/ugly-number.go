package main

import (
	"fmt"
)

func isUgly(n int) bool {
	if n <= 0 {
		return false
	}
	for _, p := range []int{2, 3, 5} {
		for n % p == 0 {
			n /= p
		}
	}
	return n == 1
}

func main() {
	tests := []int{
		6,
		1,
		14,
	}

	for _, n := range tests {
		fmt.Printf("---\nn: %d\nisUgly: %t\n", n, isUgly(n))
	}
}
