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

func binaryTreePaths(root *TreeNode) []string {
  var paths []string

	var dfs func(node *TreeNode, path string)
	dfs = func(node *TreeNode, path string) {
		if node == nil {
			return
		}

		if path == "" {
			path = fmt.Sprintf("%d", node.Val)
		} else {
			path = fmt.Sprintf("%s->%d", path, node.Val)
		}

		if node.Left == nil && node.Right == nil {
			paths = append(paths, path)
			return
		}

		dfs(node.Left, path)
		dfs(node.Right, path)
	}
	dfs(root, "")
	return paths
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

func printTree(node *TreeNode) {
	if node == nil {
		return
	}
	printTree(node.Left)
	fmt.Printf("%d -> ", node.Val)
	printTree(node.Right)
}

func main() {
	tests := []string{
		"4,2,7,1,3,6,9",
		"2,1,3",
		"",
	}

	for _, t := range tests {
		tree := BuildTree(t)
		fmt.Printf("---\ntree: ")
		printTree(tree)
		fmt.Printf("\n binaryTreePaths: %s\n", binaryTreePaths(tree))
	}
}
