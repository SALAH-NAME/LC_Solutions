package main

import (
	"fmt"
)

func lengthOfLastWord(s string) int {
	i := len(s) - 1

	for i >= 0 && s[i] == ' ' {
		i--
	}

	length := 0
	for i >= 0 && s[i] != ' ' {
		length++
		i--
	}
	return length
}

func main() {
	tests := []string{
		"Hello World",
		"   fly me   to   the moon  ",
		"luffy is still joyboy",
	}
	for _, t := range tests {
		fmt.Printf("---\ns=\"%s\" => len: %d\n", t, lengthOfLastWord(t))
	}
}
