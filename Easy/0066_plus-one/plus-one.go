package main

import (
	"fmt"
)

func plusOne(digits []int) []int {
	carry := 1
  for i := len(digits) - 1; i >= 0; i-- {
		digits[i] += carry
		if (digits[i] < 10) {
			return digits
		}
		digits[i] = 0
		carry = 1
	}
	if carry == 1 {
		digits = append([]int{1}, digits...)
	}
	return digits
}

func main() {
	tests := [][]int{
 		{1,2,3},
		{4,3,2,1},
		{9},
		{9, 9, 9, 9},
	}

	for _, t := range tests {
		fmt.Printf("---\ndigits: %v\n", t)
		fmt.Printf("plusOne: %v\n", plusOne(t))
	}
}
