package main

import (
	"fmt"
)

func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	i := 0
	for j := 1; j < len(nums); j++ {
		if nums[i] != nums[j] {
			i++
			nums[i] = nums[j]
		}
	}
	return i + 1
}

func main() {
	tests := [][]int{
		{0,0,1,1,1,2,2,3,3,4},
		{1,1,2},
    {1,1,2,4,4,7,7},
	}

	for _, t := range tests {
		fmt.Printf("---\nOrigin:> %v\nDuplicates:> %d\nResult:> %v\n", t, removeDuplicates(t), t)
	}
}
