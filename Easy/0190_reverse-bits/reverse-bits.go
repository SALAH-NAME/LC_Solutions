package main

import (
	"fmt"
)

func reverseBits(n int) int {
  rev := 0
	for i := 0; i < 32; i++ {
		rev = (rev << 1) | (n & 1)
		n >>= 1
	}
	return rev
}

func main() {
	tests := []int{
		43261596,
		2147483644,
		0,
		1,
	}

	for _, n := range tests {
		fmt.Printf("---\nN, %d", n)
		fmt.Printf("reverseBits: %d\n", reverseBits(n))
	}
}
