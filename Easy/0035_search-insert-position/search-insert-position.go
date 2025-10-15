package main

import (
	"fmt"
)

func searchInsert(nums []int, target int) int {
	left := 0
	right := len(nums) - 1

	for left <= right {
		mid := left + (right - left) / 2
		if nums[mid] == target {
			return mid
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return left
}

type testCase struct {
	arr []int
	target int
}

func main() {
	tests := []testCase{
		{arr: []int{1,3,5,6}, target:5},
		{arr: []int{1,3,5,6}, target:2},
		{arr: []int{1,3,5,6}, target:7},
	}

	for _,tc := range tests {
		fmt.Printf("---\nnums= %v\ntarget= %d\nres= %d\n", tc.arr, tc.target, searchInsert(tc.arr, tc.target))
	}
}
