package main

import (
	"fmt"
)

type ListNode struct {
	Val int
	Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}
	pa, pb := headA, headB
	for pa != pb {
		if pa != nil {
			pa = pa.Next
		} else {
			pa = headB
		}
		if pb != nil {
			pb = pb.Next
		} else {
			pb = headA
		}
	}
  return pa
}

func buildList(values []int) *ListNode {
	dummy := &ListNode{}
	curr := dummy
	for _, v := range values {
		curr.Next = &ListNode{Val: v}
		curr = curr.Next
	}
	return dummy.Next
}

func buildAttachLists(listA, listB []int, intersectA, intersectB int) (*ListNode, *ListNode) {
	headA := buildList(listA)
	headB := buildList(listB)

	if intersectA == - 1 || intersectB == -1 {
		return headA, headB
	}

	intersectNode := headA
	for i := 0; i < intersectA && intersectNode != nil; i++ {
		intersectNode = intersectNode.Next
	}

	attachPoint := headB
	for i := 0; i < intersectB && attachPoint != nil; i++ {
		attachPoint = attachPoint.Next
	}

	if attachPoint != nil {
		attachPoint.Next = intersectNode
	}
	return headA, headB
}


type testCase struct {
	lA []int
	lB []int
	interA int
interB int
}

func main() {
	tests := []testCase{
		{[]int{4, 1, 8, 4, 5}, []int{5, 6, 1, 8, 4, 5}, 2, 3},
		{[]int{1, 9, 1, 2, 4}, []int{3, 2, 4}, 3, 1},
		{[]int{2, 6, 4}, []int{1, 5}, 3, 2},
	}

	for _, t := range tests {
		fmt.Printf("---\nlistA: %v listB: %v ", t.lA, t.lB)
		fmt.Printf("intersectA: %d intersectB: %d\n", t.interA, t.interB)

		headA, headB := buildAttachLists(t.lA, t.lB, t.interA, t.interB)
		node := getIntersectionNode(headA, headB)

		if node != nil {
			fmt.Printf("intersectNode: %d\n", node.Val)
		} else {
			fmt.Printf("intersectNode: nil\n")
		}
	}
}
