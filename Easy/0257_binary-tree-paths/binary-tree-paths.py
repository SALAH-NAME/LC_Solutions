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
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        paths = []

        def dfs(node, path):
            if not node:
                return
            path += str(node.val)
            if not node.left and not node.right:
                paths.append(path)
            else:
                path += "->"
                dfs(node.left, path)
                dfs(node.right, path)
        dfs(root, "")
        return paths

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

def printTree(node: TreeNode) -> None:
    if not node:
        return
    printTree(node.left)
    print(node.val,end=' ')
    printTree(node.right)

def main():
    tests: List[str] = [
        "1,2,3,null,5",
        "1",
    ]

    for t in tests:
        tree = buildTree(t)
        print(f"---\ntree: ",end='')
        printTree(tree)
        print(f"\nbinaryTreePaths: {Solution().binaryTreePaths(tree)}")
 
if __name__ == "__main__":
    main()

