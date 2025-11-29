package main

import (
	"fmt"
)

func addDigits(num int) int {
  if num == 0 {
		return 0
	}
	return 1 + (num - 1) % 9
}

func main() {
	tests := []int{
		38,
		0,
	}

	for _, n := range tests {
		fmt.Printf("---\nnum: %d\naddDigits: %d\n", n, addDigits(n))
	}
}
