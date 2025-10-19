package main

import (
	"fmt"
)

func mySqrt(x int) int {
	if (x < 2)	{
		return x
	}

	r := x
	for r * r > x {
		r = (r + x / r) / 2
	}
  return r
}

func main() {
	tests := []int{
		4,
		8,
		16,
		0,
		2,
		1,
	}

	for _, x := range tests {
		fmt.Printf("---\nx=%d => srqt= %d\n", x, mySqrt(x))
	}
}
