package main

import (
	"fmt"
)

func singleNumber(nums []int) int {
  ans := 0
	for _, n := range nums {
		ans ^= n
	}
	return ans
}

func main() {
	tests := [][]int{
		{2,2,1},
		{4,1,2,1,2},
		{1},
	}

	for _, nums := range tests {
		fmt.Printf("---\nnums= %v\nsingleNumber: %d\n", nums, singleNumber(nums));
	}
}
