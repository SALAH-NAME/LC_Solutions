package main

import (
	"fmt"
)

func removeElement(nums []int, val int) int {
	i := 0
	for _, n := range nums {
		if (n != val) {
			nums[i] = n
			i++
		}
	}
	return i
}

type testCase struct {
	arr []int
	val int
}

func main() {
	tests := []testCase{
	      {arr: []int{3,2,2,3}, val: 3},
	      {arr: []int{0,1,2,2,3,0,4,2}, val: 2},
	      {arr: []int{3}, val: 3},
	}

	for _, tc := range tests {
		fmt.Println("---")
		fmt.Printf("arr: %v\nval: %d\n", tc.arr, tc.val)

		res := removeElement(tc.arr, tc.val)
		fmt.Printf("--after_solution--\nres: %d\nresArr: %v\n", res, tc.arr[:res])
	}
}
