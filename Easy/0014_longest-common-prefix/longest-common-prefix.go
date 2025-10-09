package main

import (
	"fmt"
)

func longestCommonPrefix(strs []string) string {
	minLen := len(strs[0])
	for _, s := range strs {
		if len(s) < minLen {
			minLen = len(s)
		}
	}

	for i := 0; i < minLen; i++{
		c := strs[0][i]
		for _, s := range strs {
			if c != s[i] {
				return strs[0][:i]
			}
		}
	}
	return strs[0][:minLen]
}

func main() {
	tests := [][]string{
				{"flower", "flow", "flight"},
        {"dog", "racecar", "car"},
        {"a"},
	}

	for _, t := range tests {
		fmt.Printf("%v => %s\n", t, longestCommonPrefix(t))
	}
}
