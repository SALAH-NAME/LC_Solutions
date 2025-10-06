package main

import "fmt"

func twoSum(nums []int, target int) []int {
	seen := make(map[int]int)

	for i, n := range nums {
		comp := target - n
		if idx, ok := seen[comp]; ok {
			return []int{idx, i}
		}
		seen[n] = i
	}
	return nil
}

func main() {
	nums := []int{2, 7, 11, 15}
	target := 9;
	result := twoSum(nums, target)
	fmt.Println(result)
}
