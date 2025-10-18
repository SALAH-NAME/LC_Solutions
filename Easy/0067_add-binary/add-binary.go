package main

import (
	"fmt"
)

func addBinary(a string, b string) string {
	i, j := len(a) - 1, len(b) - 1
	carry := 0
	max := 1

	if len(a) > len(b) {
		max += len(a)
	} else {
		max += len(b)
	}

	result := make([]byte, 0, max)
	for i >= 0 || j >= 0 || carry > 0 {
		if (i >= 0) {
			carry += int(a[i] - '0')
			i -= 1
		}
		if (j >= 0) {
			carry += int(b[j] - '0')
			j -= 1
		}
		result = append(result, byte(carry % 2) + '0')
		carry /= 2
	}

	for k, n := 0, len(result); k < n/2; k++ {
		result[k], result[n-1-k] = result[n-1-k], result[k]
	}
	return string(result)
}

type testCase struct {
	a, b string
}

func main() {
	tests := []testCase{
		{"11", "1"},
		{"1010", "1011"},
		{"111111", "1"},
	}

	for _, tc := range tests {
		fmt.Printf("---\na='%s' b='%s' => %s\n", tc.a, tc.b, addBinary(tc.a, tc.b))
	}
}
