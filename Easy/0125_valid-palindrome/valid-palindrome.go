package main

import (
	"fmt"
)

func isAlnum(b byte) bool {
	return (b >= '0' && b <= '9') ||
		(b >= 'A' && b <= 'Z') ||
		(b >= 'a' && b <= 'z')
}

func toLower(b byte) byte {
	if b >= 'A' && b <= 'Z' {
		return b + ('a' - 'A')
	}

	return b
}

func isPalindrome(s string) bool {
	i, j := 0, len(s) - 1

	for i < j {
		for i < j && !isAlnum(s[i]) {
			i++
		}
		for i < j && !isAlnum(s[j]) {
			j--
		}
		if toLower(s[i]) != toLower(s[j]) {
			return false
		}
		i++
		j--
	}
	return true
}

func main() {
	tests := []string{
		"A man, a plan, a canal: Panama",
		"race a car",
		" ",
		"a",
	}

	for _, s := range tests {
		fmt.Printf("---\ns='%s'\nisPalindrome: %t\n", s, isPalindrome(s))
	}
}
