package main

import (
	"fmt"
)

func titleToNumber(columnTitle string) int {
  res := 0
	for _, c := range columnTitle {
		res = res * 26 + (int(c) - int('A') + 1)
	}
	return res
}

func main() {
	tests := []string{
		"A",
		"AB",
		"ZY",
	}
	for _, t := range tests {
		fmt.Printf("---\nTitle: '%s' Number: %d\n", t, titleToNumber(t))
	}
}
