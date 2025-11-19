package main

import (
	"fmt"
)

func containsNearbyDuplicate(nums []int, k int) bool {
	seen := make(map[int]int, len(nums))

	for i, n := range nums {
		if idx, found := seen[n]; found && i - idx <= k {
			return true
		}
		seen[n] = i
	}
  return false
}

type testCase struct {
	nums []int
	k int
}

func main() {
	tests := []testCase{
		{[]int{1,2,3,1}, 3},
		{[]int{1,0,1,1}, 1},
		{[]int{1,2,3,1,2,3}, 2},
	}

	for _, tc := range tests {
		fmt.Printf("---\nnums: %v k: %d\n", tc.nums, tc.k)
		fmt.Printf("containsNearbyDuplicate: %t\n", containsNearbyDuplicate(tc.nums, tc.k))
	}
}
