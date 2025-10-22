package main

import (
	"fmt"
)

func merge(nums1 []int, m int, nums2 []int, n int) {
	i, j, k := m - 1, n - 1, m + n - 1

	for (j >= 0) {
		if i >= 0 && nums1[i] > nums2[j] {
			nums1[k] = nums1[i]
			i -= 1
		} else {
			nums1[k] = nums2[j]
			j -= 1
		}
		k -= 1
	}
}

type testCase struct {
	nums1 []int
	m int
	nums2 []int
	n int
}

func main() {
	tests := []testCase{
		{nums1: []int{1,2,3,0,0,0},m:3, nums2:[]int{2,5,6},n:3},
		{nums1: []int{1},m:1, nums2:[]int{},n:0},
		{nums1: []int{0},m:0, nums2:[]int{1},n:1},
	}

	for _, tc := range tests {
		fmt.Printf("---\nnums1: %v, m: %d, nums2: %v, n: %d\n", tc.nums1, tc.m, tc.nums2, tc.n)
		merge(tc.nums1, tc.m, tc.nums2, tc.n)
		fmt.Printf("merge: %v\n", tc.nums1)
	}
}
