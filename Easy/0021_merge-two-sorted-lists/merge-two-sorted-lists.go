package main

import (
	"fmt"
)

type ListNode struct {
	Val int
	Next *ListNode
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	dummy := &ListNode{}
	tail := dummy

	for list1 != nil && list2 != nil {
		if (list1.Val <= list2.Val) {
			tail.Next = list1
			list1 = list1.Next
		} else {
			tail.Next = list2
			list2 = list2.Next
		}
		tail = tail.Next
	}

	tail.Next = list1
	if tail.Next == nil {
		tail.Next = list2
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
	l1 []int
	l2 []int
}

func main() {
	tests := []Unit{
		{l1: []int{1, 2, 4}, l2: []int{1, 3, 4}},
		{l1: []int{}, l2: []int{1}},
		{l1: []int{1}, l2: []int{}},
		{l1: []int{}, l2: []int{}},
	}

	for _, t := range tests {
		l1 := buildLinkedList(t.l1)
		l2 := buildLinkedList(t.l2)

		fmt.Println("---")
		fmt.Println("Input 1:", t.l1)
		fmt.Println("Input 2:", t.l2)
		fmt.Println("Result:")
		res := mergeTwoLists(l1, l2)
		printLinkedList(res)
	}
}
