package main

import (
	"fmt"
)

type ListNode struct {
	Val int
	Next *ListNode
}

func removeElements(head *ListNode, val int) *ListNode {
	dummy := &ListNode{Next: head}
	current := dummy

	for current.Next != nil {
		if current.Next.Val == val {
			current.Next = current.Next.Next
		} else {
			current = current.Next
		}
	}
  return dummy.Next
}

func buildLinkedList(values []int) *ListNode {
	dummy := &ListNode{}
	current := dummy
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
	fmt.Println("nil")
}

type Unit struct {
	l []int
	v int
}

func main() {
	tests := []Unit{
		{l: []int{1, 2, 6, 3, 4, 5, 6}, v: 6},
		{l: []int{}, v: 1},
		{l: []int{7, 7, 7, 7}, v: 7},
	}

	for _, t := range tests {
		fmt.Printf("---\nlist: ")
		list := buildLinkedList(t.l)
		printLinkedList(list)
		fmt.Printf("afterRemove: ")
		res := removeElements(list, t.v)
		printLinkedList(res)
		fmt.Printf("\n")
	}
}
