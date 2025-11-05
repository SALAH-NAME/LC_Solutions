#!/bin/python3

from typing import List, Optional
from dataclasses import dataclass

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return False
        slow = head
        fast = head.next
        while fast and fast.next:
            if slow == fast:
                return True
            slow = slow.next
            fast = fast.next.next
        return False

def createCycleLinkedList(values: List[int], pos: int):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    nodes = [head]
    for val in values[1:]:
        node = ListNode(val)
        current.next = node
        current = node
        nodes.append(node)
    if pos != -1:
        current.next = nodes[pos]
    return head

@dataclass
class testCase:
    nums: List[int]
    pos: int

def main():
    tests: List[testCase] = [
        testCase([3, 2, 0, -4], 1),
        testCase([1,2], 0),
        testCase([1], -1),
    ]

    for test in tests:
        nums = test.nums
        pos = test.pos
        print(f"---\nList: {nums} pos: {pos}")
        head = createCycleLinkedList(nums, pos)
        print(f"hasCycle: {Solution().hasCycle(head)}")

if __name__ == "__main__":
    main()
