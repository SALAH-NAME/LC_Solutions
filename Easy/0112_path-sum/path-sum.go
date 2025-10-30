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

func hasPathSum(root *TreeNode, targetSum int) bool {
	if root == nil {
		return false
	}
	if root.Left == nil && root.Right == nil {
		return root.Val == targetSum
	}
	targetSum -= root.Val
	return hasPathSum(root.Left, targetSum) || hasPathSum(root.Right, targetSum)
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

type testCase struct {
	tree string
	sum int
}

func main() {
	tests := []testCase{
		{"5,4,8,11,null,13,4,7,2,null,null,null,1", 22},
		{"1,2,3", 5},
		{"", 0},
	}

	for _, tc := range tests {
		root := buildTree(tc.tree)
		fmt.Printf("---\nTree: [%s] Sum: %d\n", tc.tree, tc.sum)
		fmt.Printf("hasPathSum: %t\n", hasPathSum(root, tc.sum))
	}
}
