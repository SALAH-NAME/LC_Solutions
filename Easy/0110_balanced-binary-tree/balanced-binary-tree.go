package main

import (
	"fmt"
	"strconv"
	"strings"
)

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func check(node *TreeNode) int {
	if node == nil {
		return 0
	}

	left := check(node.Left)
	if left == -1 {
		return -1
	}

	right := check(node.Right)
	if right == -1 {
		return -1
	}

	if abs(left - right) > 1 {
		return -1
	}
	return max(left, right) + 1
}

func isBalanced(root *TreeNode) bool {
  return check(root) != -1
}

func buildTree(data string) *TreeNode {
	if data == "" {
		return nil
	}

	values := strings.Split(data, ",")
	if len(values) == 0 || values[0] == "null" {
		return nil
	}

	val, err := strconv.Atoi(values[0])
	if err != nil {
		return nil
	}
	root := &TreeNode{Val: val}

	queue := []*TreeNode{root}
	i := 1

	for len(queue) > 0 && i < len(values) {
		node := queue[0]
		queue = queue[1:]

		if i < len(values) && values[i] != "null" {
			if v, err := strconv.Atoi(values[i]); err == nil {
				node.Left = &TreeNode{Val: v}
				queue = append(queue, node.Left)
			}
		}
		i++

		if i < len(values) && values[i] != "null" {
			if v, err := strconv.Atoi(values[i]); err == nil {
				node.Right = &TreeNode{Val: v}
				queue = append(queue, node.Right)
			}
		}
		i++
	}
	return root
}

func main() {
	tests := []string{
		"3,9,20,null,null,15,7",
		"1,2,2,3,3,null,null,4,4",
		"",
		"1,2,2,3,null,null,3,4,null,null,4",
	}

	for _, tc := range tests {
		tree := buildTree(tc)
		fmt.Printf("---\ntree: [%s]\nisBalanced: %t\n", tc, isBalanced(tree))
	}
}
