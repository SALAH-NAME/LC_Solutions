#!/bin/python3

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

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
    tests : List[str]= [
        "3,9,20,null,null,15,7",
        "1,null,2"
    ]

    for tc in tests:
        root = buildTree(tc)
        print(f"---\nList=[{tc}]\nMaxDepth: {Solution().maxDepth(root)}")

if __name__ == "__main__":
    main()
