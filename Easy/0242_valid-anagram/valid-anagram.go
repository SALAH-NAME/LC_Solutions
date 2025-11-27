package main

import (
	"fmt"
)

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	var count [26]int
	for _, ch := range s {
		count[ch - 'a']++
	}
	for _, ch := range t {
		count[ch - 'a']--
		if count[ch - 'a'] < 0 {
			return false
		}
	}
	return true
}

func main() {
	tests := [][]string{
		{"anagram", "nagaram"},
		{"rat", "car"},
	}

	for _, tc := range tests {
		fmt.Printf("---\ns: %q, t: %q\nisAnagram: %t\n", tc[0], tc[1], isAnagram(tc[0], tc[1]))
	}
}
