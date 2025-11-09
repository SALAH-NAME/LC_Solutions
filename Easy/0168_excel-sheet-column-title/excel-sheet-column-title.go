package main

import (
	"fmt"
)

func convertToTitle(columnNumber int) string {
	result := make([]byte, 0)
	for columnNumber > 0 {
		columnNumber--
		result = append(result, byte('A' + columnNumber % 26))
		columnNumber /= 26
	}

	for i, j := 0, len(result)-1; i < j; i, j = i+1, j-1 {
		result[i], result[j] = result[j], result[i]
	}
  return string(result)
}

func main() {
	tests := []int{
		1,
		28,
		701,
	}

	for _, n := range tests {
		fmt.Printf("---\nNumber: %d Title: %s\n", n, convertToTitle(n))
	}
}
