package main

import (
	"fmt"
)

func isIsomorphic(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	sMap := make([]int, 256)
	tMap := make([]int, 256)

	for i := 0; i < len(s); i++ {
		cs := s[i]
		ct := t[i]

		if sMap[cs] != tMap[ct] {
			return false
		}
		sMap[cs] = i + 1
		tMap[ct] = i + 1
	}
  return true
}

type testCase struct {
	s string
	t string
}

func main() {
	tests := []testCase{
		{"egg", "add"},
		{"foo", "bar"},
		{"paper", "title"},
	}

	for _, t := range tests {
		fmt.Printf("---\ns= '%s' t= '%s'\n", t.s, t.t)
		fmt.Printf("isIsomorphic: %t\n", isIsomorphic(t.s, t.t))
	}
}
