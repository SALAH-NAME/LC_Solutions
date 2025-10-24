#!/bin/python3

from typing import List, Optional
from dataclasses import dataclass
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        if not p or not q:
            return False
        return q.val == p.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

def buildTree(data: str) -> TreeNode:
    if not data:
        return None
    values = data.split(",")
    if not values or values[0] == "null":
        return None
    root = TreeNode(int(values[0]))
    queue = deque([root])
    i = 1
    while queue and i < len(values):
        node = queue.popleft()
        if i < len(values) and values[i] != "null":
            node.left = TreeNode(int(values[i]))
            queue.append(node.left)
        i += 1
        if i < len(values) and values[i] != "null":
            node.right = TreeNode(int(values[i]))
            queue.append(node.right)
        i += 1
    return root

@dataclass
class TestCase:
    p : str
    q : str

def main():
    tests: List[TestCase] = [
        TestCase(p= "1,2,3", q= "1,2,3"),
        TestCase(p= "1,2", q= "1,null,3"),
        TestCase(p= "1,2,1", q= "1,1,2"),
    ]

    for tc in tests:
        q = buildTree(tc.q)
        p = buildTree(tc.p)
        print(f"---\np=[{tc.p}] q=[{tc.q}]\nIsTheSame: {Solution().isSameTree(q, p)}")

if __name__ == "__main__":
    main()
