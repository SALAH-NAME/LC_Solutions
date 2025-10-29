#!/bin/python3

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def check(self, node: Optional[TreeNode]) -> int:
        if not node:
            return 0

        left = self.check(node.left)
        if left == -1:
            return -1

        right = self.check(node.right)
        if right == -1:
            return -1

        if abs(left - right) > 1:
            return -1
        return max(left, right) + 1

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.check(root) != -1

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
        "3,9,20,null,null,15,7",
        "1,2,2,3,3,null,null,4,4",
        "",
        "1,2,2,3,null,null,3,4,null,null,4",
    ]

    for tc in tests:
        tree = buildTree(tc)
        print(f"---\ntree=[{tc}]\nisBalanced: {Solution().isBalanced(tree)}")

if __name__ == "__main__":
    main()
