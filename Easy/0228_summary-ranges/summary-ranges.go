package main

import (
	"fmt"
	"strconv"
)

func summaryRanges(nums []int) []string {
	res := []string{}
	n := len(nums)
	i := 0

	for i < n {
		start := nums[i]

		for i + 1 < n && nums[i + 1] == nums[i] + 1 {
			i++
		}

		end := nums[i]
		if start == end {
			res = append(res, strconv.Itoa(start))
		} else {
			res = append(res, strconv.Itoa(start) + "->" + strconv.Itoa(end))
		}
		i++
	}
	return res
}

func main() {
	tests := [][]int{
		{0,1,2,4,5,7},
		{0,2,3,4,6,8,9},
	}

	for _, nums := range tests {
		fmt.Printf("---\nnums: %v\n", nums)
		fmt.Printf("summaryRanges: %v\n", summaryRanges(nums))
	}
}
