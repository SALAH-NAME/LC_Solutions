package main

import (
	"fmt"
)

func missingNumber(nums []int) int {
	n := len(nums)
	expected := n * (n + 1) / 2
	actual := 0
	for _, num := range nums {
		actual += num
	}
	return expected - actual
}

func main() {
	tests := [][]int{
		[]int{3,0,1},
		[]int{0,1},
		[]int{9,6,4,2,3,5,7,0,1},
	}

	for _, nums := range tests {
		fmt.Printf("---\nnums: %v\n", nums)
		fmt.Printf("missingNumber: %d\n", missingNumber(nums))
	}
}
