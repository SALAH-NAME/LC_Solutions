package main

import (
	"fmt"
)

type ListNode struct {
	Val int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	current := head
	for current.Next != nil {
		if current.Val == current.Next.Val {
			current.Next = current.Next.Next
		} else {
			current = current.Next
		}
	}
  return head
}

func buildLinkedList(arr []int) *ListNode {
	if (len(arr) == 0) {
		return nil
	}

	head := &ListNode{Val: arr[0]}
	current := head

	for i := 1; i < len(arr); i++ {
		current.Next = &ListNode{Val: arr[i]}
		current = current.Next
	}
	return head
}

func printList(head *ListNode) {
	for head != nil {
		fmt.Print(head.Val, " -> ")
		head = head.Next
	}
	fmt.Println("nil")
}

func main() {
	tests := [][]int{
		{1,1,2},
		{1,1,2,3,3},
		{1,2,3,4},
		{1,1,1,1},
		{},
	}

	for _, tc := range tests {
		fmt.Printf("---\narr= %v\nlist= ", tc)
		list := buildLinkedList(tc)
		list = deleteDuplicates(list)
		printList(list)
	}
}
