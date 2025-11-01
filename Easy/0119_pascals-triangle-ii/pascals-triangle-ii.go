package main

import (
	"fmt"
)

func getRow(rowIndex int) []int {
  row := make([]int, rowIndex + 1)
	row[0] = 1
	for i := 1; i <= rowIndex; i++ {
		for j := i ; j > 0 ; j-- {
			row[j] += row[j - 1]
		}
	}
	return row
}

func main() {
	tests := []int{
		3,
		0,
		1,
	}

	for _, n := range tests {
		fmt.Printf("---\nn: %d\nRow: %v\n", n, getRow(n))
	}
}
