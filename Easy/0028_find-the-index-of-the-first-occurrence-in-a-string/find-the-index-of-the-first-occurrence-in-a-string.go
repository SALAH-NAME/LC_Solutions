package main

import (
	"fmt"
	"strings"
)

func strStr(haystack string, needle string) int {
	return strings.Index(haystack, needle)
}

type testCase struct {
	haystack string
	needle string
}

func main() {
	tests := []testCase{
		{haystack: "sadbutsad", needle: "sad"},
		{haystack: "leetcode", needle: "leeto"},
	}

	for _, tc := range tests {
		fmt.Printf("---\nhaystack: %s\nneedle: %s\nstrStr: %d\n", tc.haystack, tc.needle, strStr(tc.haystack, tc.needle))
	}
}
