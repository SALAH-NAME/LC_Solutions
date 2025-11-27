package main

import (
	"fmt"
)

type ListNode struct {
	Val int
	Next *ListNode
}

func isPalindrome(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return true
	}

	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	var prev *ListNode
	curr := slow
	for curr != nil {
		nxt := curr.Next
		curr.Next = prev
		prev = curr
		curr = nxt
	}

	left, right := head, prev
	for right != nil {
		if left.Val != right.Val {
			return false
		}
		left = left.Next
		right = right.Next
	}
	return true
}

func buildLinkedList(values []int) *ListNode {
	dummy := ListNode{}
	current := &dummy
	for _, v := range values {
		current.Next = &ListNode{Val: v}
		current = current.Next
	}
	return dummy.Next
}

func printLinkedList(node *ListNode) {
	for node != nil {
		fmt.Printf("%d => ", node.Val)
		node = node.Next
	}
	fmt.Printf("nil\n")
}

func main() {
	tests := [][]int{
		{1,2,3,4,5},
		{1,2},
		{1},
	}

	for _, t := range tests {
		l := buildLinkedList(t)
		fmt.Printf("---\nList: ")
		printLinkedList(l)
		fmt.Printf("isPalindrome: %t\n", isPalindrome(l))
	}
}
