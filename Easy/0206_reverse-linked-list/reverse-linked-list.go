package main

import (
	"fmt"
)

type ListNode struct {
	Val int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	var prev *ListNode = nil
	current := head

	for current != nil {
		tmp := current.Next
		current.Next = prev
		prev = current
		current = tmp
	}
	return prev
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
		{},
	}

	for _, t := range tests {
		l := buildLinkedList(t)
		fmt.Printf("---\nList: ")
		printLinkedList(l)
		fmt.Printf("reversedList: ")
		reversed := reverseList(l)
		printLinkedList(reversed)
	}
}
