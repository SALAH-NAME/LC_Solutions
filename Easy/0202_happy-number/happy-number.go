package main

import (
	"fmt"
)

func sumSquares(n int) int {
	sum := 0
	for n > 0 {
		d := n % 10
		sum += d * d
		n /= 10
	}
	return sum
}

func isHappy(n int) bool {
	slow, fast := n, sumSquares(n)

	for fast != 1 && slow != fast {
		slow = sumSquares(slow)
		fast = sumSquares(sumSquares(fast))
	}
	return fast == 1
}

func main() {
	tests := []int{
		19,
    2,
    1,
    10,
    42,
    2147483647,
	}

	for _, n := range tests {
		fmt.Printf("---\nN: %d, isHappy: %t\n", n, isHappy(n))
	}
}
