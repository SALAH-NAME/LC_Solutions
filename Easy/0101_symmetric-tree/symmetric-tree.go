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

func isSymmetric(root *TreeNode) bool {
	var isSym func(p *TreeNode, q *TreeNode) bool

	isSym = func(p *TreeNode, q *TreeNode) bool {
		if p == nil && q == nil {
			return true
		}
		if p == nil || q == nil {
			return false
		}
		return p.Val == q.Val && isSym(p.Left, q.Right) && isSym(p.Right, q.Left)
	}
	return isSym(root.Left, root.Right)
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
		"1,2,2,3,4,4,3",
		"1,2,2,null,3,null,3",
		"1",
	}

	for _, tc := range tests {
		tree := buildTree(tc)
		fmt.Printf("---\nList=[%s]\nisSymmetric: %t\n", tc, isSymmetric(tree))
	}
}
