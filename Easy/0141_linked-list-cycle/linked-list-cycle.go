package main

import (
	"fmt"
)

type ListNode struct {
	Val int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return false
	}
	slow := head
	fast := head.Next
	for fast != nil && fast.Next != nil {
		if slow == fast {
			return true
		}
		slow = slow.Next
		fast = fast.Next.Next
	}
	return false
}

func createCycleLinkedList(values []int, pos int) *ListNode {
	if len(values) == 0 {
		return nil
	}

	head := &ListNode{Val: values[0]}
	current := head
	nodes := []*ListNode{head}
	for i := 1; i < len(values); i++ {
		node := &ListNode{Val: values[i]}
		current.Next = node
		current = node
		nodes = append(nodes, node)
	}
	if pos != -1 {
		current.Next = nodes[pos]
	}
	return head
}

type testCase struct {
	nums []int
	pos int
}

func main() {
	tests := []testCase{
		{[]int{3, 2, 0, -4}, 1},
		{[]int{1,2}, 0},
		{[]int{1}, -1},
	}
	
	for _, tc := range tests {
		head := createCycleLinkedList(tc.nums, tc.pos)
		fmt.Printf("---\nList: %v pos: %d\n", tc.nums, tc.pos)
		fmt.Printf("hasCycle: %t\n", hasCycle(head))
	}
}
