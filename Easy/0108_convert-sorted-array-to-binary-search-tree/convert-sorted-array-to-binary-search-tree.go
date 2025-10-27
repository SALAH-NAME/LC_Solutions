package main

import (
	"fmt"
)

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func buildBalanceBST(nums []int, start int, end int) *TreeNode {
	if (start > end) {
		return nil
	}
	mid := (start + end) / 2
	node := &TreeNode{Val: nums[mid]}
	node.Left = buildBalanceBST(nums, start, mid - 1)
	node.Right = buildBalanceBST(nums, mid + 1, end)
	return node
}

func sortedArrayToBST(nums []int) *TreeNode {
	return buildBalanceBST(nums, 0, len(nums) - 1)
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
	tests := [][]int{
		{-10,-3,0,5,9},
		{1,3},
	}

	for _, tc := range tests {
		fmt.Printf("---\nnums= [%v]\nTree: ", tc)
		tree := sortedArrayToBST(tc)
		printTree(tree)
		fmt.Println("nil")
	}
}
