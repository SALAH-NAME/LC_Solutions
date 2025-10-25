#!/bin/python3

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSym(self, left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
        if not left and not right:
            return True
        if not left or not right:
            return False
        return left.val == right.val and self.isSym(left.left, right.right) and self.isSym(left.right, right.left)
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.isSym(root.left, root.right)


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

def main():
    tests: List[str]=[
        "1,2,2,3,4,4,3",
        "1,2,2,null,3,null,3",
    ]

    for tc in tests:
        tree:TreeNode = buildTree(tc)
        print(f"---\nlist=[{tc}]\nisSymmetric: {Solution().isSymmetric(tree)}")

if __name__ == "__main__":
    main()
