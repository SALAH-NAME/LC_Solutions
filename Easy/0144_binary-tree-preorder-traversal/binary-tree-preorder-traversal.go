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

func preorderTraversal(root *TreeNode) []int {
	var result []int

	var dfs func(node *TreeNode)
	dfs = func(node *TreeNode) {
		if node == nil {
			return
		}
		result = append(result, node.Val)
		dfs(node.Left)
		dfs(node.Right)
	}
	dfs(root)
  return result
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
		"1,null,2,3",
		"1,2,3,4,5,null,8,null,null,6,7,9",
		"1",
		"",
	}

	for _, t := range tests {
		tree := buildTree(t)
		fmt.Printf("---\nTree: [%s]\n", t)
		fmt.Printf("preorderTraversal: %d\n", preorderTraversal(tree))
	}
}
