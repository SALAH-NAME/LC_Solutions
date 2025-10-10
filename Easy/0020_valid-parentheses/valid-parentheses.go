package main

import (
	"fmt"
)

func isValid(s string) bool {
  pair := map[rune]rune{
		')': '(',
		'}': '{',
		']': '[',
	}

	stack := make([]rune, 0, len(s))

	for _, ch := range s {
		switch ch {
			case '(', '[', '{':
				stack = append(stack, ch)

			case ')', ']', '}':
				if len(stack) == 0 || stack[len(stack) - 1] != pair[ch] {
					return false
				}
				stack = stack[:len(stack) - 1]

			default:
				return false
		}
	}
	return len(stack) == 0
}

func main() {
	tests := []string{
		"()",
		"()[]{}",
		"(]",
		"([])",
		"([)]",
		"",
	}

	for _, t := range tests {
		fmt.Printf("%q => %v\n", t, isValid(t))
	}
}
