package main

import (
	"fmt"
)

func generate(numRows int) [][]int {
	triangle := make([][]int, numRows)

	triangle[0] = []int{1}
	for i := 1; i < numRows; i++ {
		triangle[i] = make([]int, i + 1)
		triangle[i][0], triangle[i][i] = 1, 1

		for j := 1; j < i; j++ {
			triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1]
		}
	}
	return triangle
}

func main() {
	tests := []int{
		5,
		1,
	}

	for _, n := range tests {
		fmt.Printf("---\nnumRows: %d\nTriangle: %v\n", n, generate(n))
	}
}
