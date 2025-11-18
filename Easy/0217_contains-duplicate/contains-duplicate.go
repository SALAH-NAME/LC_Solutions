package main

import (
	"fmt"
	"sort"
)

func containsDuplicate(nums []int) bool {
	sort.Ints(nums)
	for i := 0; i < len(nums) - 1; i++ {
		if nums[i] == nums[i+1] {
			return true
		}
	}
	return false
}

func main() {
	tests := [][]int{
		{1,2,3,1},
		{1,2,3,4},
		{1,1,1,3,3,4,3,2,4,2},
	}

	for _, nums := range tests {
		fmt.Printf("---\nnums: %v\n", nums)
		fmt.Printf("containsDuplicate: %t\n", containsDuplicate(nums))
	}
}
