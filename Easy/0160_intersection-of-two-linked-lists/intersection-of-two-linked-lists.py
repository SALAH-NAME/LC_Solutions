#!/bin/python3

from typing import List, Optional, Tuple
from dataclasses import dataclass

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        if not headA or not headB:
            return None

        pa, pb = headA, headB

        while pa != pb:
            pa = pa.next if pa else headB
            pb = pb.next if pb else headA

        return pa

def buildAttachLists(listA: List[int], listB: List[int], intersectA: int, intersectB: int) -> Tuple[Optional[ListNode], Optional[ListNode]]:
    def buildList(values: List[int]) -> Optional[ListNode]:
        dummy = ListNode(0)
        current = dummy
        for val in values:
            current.next = ListNode(val)
            current = current.next
        return dummy.next

    headA = buildList(listA)
    headB = buildList(listB)

    if intersectA == -1 or intersectB == -1:
        return headA, headB

    intersect_node = headA
    for _ in range(intersectA):
        if intersect_node:
            intersect_node = intersect_node.next

    attach_point = headB
    for _ in range(intersectB):
        if attach_point:
            attach_point = attach_point.next

    if attach_point:
        attach_point.next = intersect_node

    return headA, headB

@dataclass
class testCase:
    listA: List[int]
    listB: List[int]
    intersectA: int
    intersectB: int

def main():
    tests: List[testCase] = [
        testCase([4,1,8,4,5], [5,6,1,8,4,5], 2, 3),
        testCase([1,9,1,2,4], [3,2,4], 3, 1),
        testCase([2,6,4], [1,5], 3, 2),
    ]

    for t in tests:
        print(f"---\nlistA: {t.listA} listB: {t.listB}", end=" ")
        print(f"intersectA: {t.intersectA} intersectB: {t.intersectB}")
        headA, headB = buildAttachLists(t.listA, t.listB, t.intersectA, t.intersectB)
        node = Solution().getIntersectionNode(headA, headB)
        print(f"intersectNode: {node.val if node else None}")

if __name__ == "__main__":
    main()
