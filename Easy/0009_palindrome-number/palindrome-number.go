package main

import (
	"fmt"
)

func isPalindrome(x int) bool {
	if x < 0 || (x % 10 == 0 && x != 0) {
		return false
	}

	reversedNumber := 0
	for x > reversedNumber {
		reversedNumber = reversedNumber * 10 + x % 10
		x /= 10
	}
	return x == reversedNumber || x == reversedNumber / 10
}

func main() {
	fmt.Println("121: ", isPalindrome(121))
	fmt.Println("-121: ", isPalindrome(-121))
	fmt.Println("122: ", isPalindrome(122))
}
