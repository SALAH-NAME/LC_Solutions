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

func minDepth(root *TreeNode) int {
  if root == nil {
		return 0
	}

	type NodeDepth struct {
		node *TreeNode
		depth int
	}

	queue := []NodeDepth{{root, 1}}

	for len(queue) > 0 {
		current := queue[0]
		queue = queue[1:]

		node := current.node
		depth := current.depth

		if node.Left == nil && node.Right == nil {
			return depth
		}

		if node.Left != nil {
			queue = append(queue, NodeDepth{node.Left, depth + 1})
		}
		if node.Right != nil {
			queue = append(queue, NodeDepth{node.Right, depth + 1})
		}
	}
	return 0
}

func BuildTree(data string) *TreeNode {
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
		"2,null,3,null,4,null,5,null,6",
		"1,null,2,3",
		"1,2,3,4,5,null,8,null,null,6,7,9",
		"",
		"1",
	}

	for _, tc := range tests {
		head := BuildTree(tc)
		fmt.Printf("---\nTree: [%s]\n", tc)
		fmt.Printf("minDepth: [%v]\n", minDepth(head))
	}
}

