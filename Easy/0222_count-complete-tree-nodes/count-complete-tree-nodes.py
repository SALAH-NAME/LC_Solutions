#!/bin/python3

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        def leftHieght(node):
            h = 0
            while node:
                h += 1
                node = node.left
            return h
        def rightHight(node):
            h = 0
            while node:
                h += 1
                node = node.right
            return h

        lh, rh = leftHieght(root), rightHight(root)

        if lh == rh:
            return (1 << lh) - 1
        else:
            return 1 + self.countNodes(root.left) + self.countNodes(root.right)


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
    tests : List[str] = [
        "1,2,3,4,5,6",
        "1",
        "",
    ]
    
    for t in tests:
        tree = buildTree(t)
        print(f"---\ntree: [{t}]\ncountNodes: {Solution().countNodes(tree)}")

if __name__ == "__main__":
    main()
