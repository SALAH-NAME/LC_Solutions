#!/bin/python3

from typing import List,Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self) -> str:
        values = []
        curr = self
        while curr:
            values.append(str(curr.val))
            curr = curr.next;
        return " -> ".join(values)

    @classmethod
    def from_list(cls, values: List[int]) -> Optional['ListNode']:
        if not values:
            return None
        head = cls(values[0])
        current = head
        for val in values[1:]:
            current.next = cls(val)
            current = current.next
        return head

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        current = head
        while current and current.next:
            if current.val == current.next.val:
                current.next = current.next.next
            else:
                current = current.next
        return head

def main():
    tests: List[List[int]] = [
        [1,1,2],
        [1,1,2,3,3],
        [1,2,3,4],
        [1,1,1,1],
        [],
    ]

    for head in tests:
        print(f"---\nhead= {head}")
        list =ListNode.from_list(head)
        list = Solution().deleteDuplicates(list)
        print(f"list= {list}")

if __name__ == "__main__":
    main()
