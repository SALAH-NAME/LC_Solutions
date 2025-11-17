#!/bin/python3

from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev , current = None, head
        while (current):
            current.next, prev, current = prev, current, current.next
        return prev

def buildLinkedList(values: List[int]) -> Optional[ListNode]:
    dummy = ListNode()
    current = dummy
    for v in values:
        current.next = ListNode(v)
        current = current.next
    return dummy.next

def printLinkedList(node: Optional[ListNode]) -> None:
    while (node):
        print(node.val, end=" -> ")
        node = node.next
    print("None")

def main():
    tests: List[List[int]] = [
        [1,2,3,4,5],
        [1,2],
        []
  ]

    for t in tests:
        l = buildLinkedList(t)
        print(f"---\nList: ",end='')
        printLinkedList(l)
        print(f"reversedList: ")
        l = Solution().reverseList(l)
        printLinkedList(l)

if __name__ == "__main__":
    main()
