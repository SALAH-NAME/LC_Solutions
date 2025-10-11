#!/bin/python3

from typing import Optional, List

class ListNode:
    def __init__(self, val:int = 0, next: Optional['ListNode'] = None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        tail = dummy

        while list1 and list2:
            if list1.val <= list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next

        tail.next = list1 if list1 else list2

        return dummy.next

def build_linked_list(values: List[int]) -> Optional[ListNode]:
    dummy = ListNode()
    current = dummy
    for v in values:
        current.next = ListNode(v)
        current = current.next
    return dummy.next

def print_linked_list(node: Optional[ListNode]) -> None:
    while (node):
        print(node.val, end=" -> ")
        node = node.next
    print ("None")

class Unit:
    def __init__(self, l1: List[int], l2: List[int]):
        self.l1 = l1
        self.l2 = l2

def main():
    tests: List[Unit] = {
        Unit([1,2,4], [1,3,4]),
        Unit([], [1]),
        Unit([1], []),
        Unit([], []),
    }
    for t in tests:
        l1 = build_linked_list(t.l1)
        l2 = build_linked_list(t.l2)
        res = Solution().mergeTwoLists(l1, l2)
        print("---")
        print("Input 1:", t.l1)
        print("Input 1:", t.l2)
        print("res:")
        print_linked_list(res)


if __name__ == "__main__":
    main()
