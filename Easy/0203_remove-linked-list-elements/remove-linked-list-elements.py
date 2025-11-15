#!/bin/python3

from typing import List, Optional
from dataclasses import dataclass

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        current = dummy

        while current.next:
            if current.next.val == val:
                current.next = current.next.next
            else:
                current = current.next
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

@dataclass
class TestCase:
    l : List[int]
    v : int

def main():
    tests : List[TestCase] = [
        TestCase([1,2,6,3,4,5,6], 6),
        TestCase([], 1),
        TestCase([7,7,7,7], 7),
    ]

    for t in tests:
        l = build_linked_list(t.l)
        print(f"---\nlist: ", end='')
        print_linked_list(l)
        l = Solution().removeElements(l, t.v)
        print(f"afterRemove: ", end='')
        print_linked_list(l)

if __name__ == "__main__":
    main()
