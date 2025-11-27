#!/bin/python3

from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return True

        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        prev = None
        curr = slow
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        left, right = head, prev
        while right:
            if left.val != right.val:
                return False
            left = left.next
            right = right.next
        return True

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
        [1,2,2,1],
        [1,2],
        [1]
  ]

    for t in tests:
        l = buildLinkedList(t)
        print(f"---\nList: ",end='')
        printLinkedList(l)
        print(f"isPalindrome: {Solution().isPalindrome(l)}")

if __name__ == "__main__":
    main()

