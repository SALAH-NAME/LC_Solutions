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
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        if not root.left and not root.right:
            return root.val == targetSum
        return (self.hasPathSum(root.left, targetSum - root.val) or
                self.hasPathSum(root.right, targetSum - root.val))

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
    tree : str
    sum : int

def main():
    tests: List[TestCase] = [
        TestCase("5,4,8,11,null,13,4,7,2,null,null,null,1", 22),
        TestCase("1,2,3", 5),
        TestCase("", 0),
    ]

    for tc in tests:
        root = buildTree(tc.tree)
        print(f"---\nTree: [{tc.tree}] Sum: {tc.sum}\nhasPathSum: {Solution().hasPathSum(root, tc.sum)}")

if __name__ == "__main__":
    main()
