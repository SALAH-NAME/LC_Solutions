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

func isSameTree(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	}
	if p == nil || q == nil {
		return false
	}
	return p.Val == q.Val && isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
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

type testCase struct {
	p string
	q string
}

func main() {
	tests := []testCase{
		{"1,2,3", "1,2,3"},
		{"1,2", "1,null,2"},
		{"1,2,1", "1,1,2"},
	}

	for _, tc := range tests {
		q := BuildTree(tc.q)
		p := BuildTree(tc.p)
		fmt.Printf("---\np=%v q=%v\nIsTheSame: %t\n", tc.p, tc.q, isSameTree(q, p))
	}
}
