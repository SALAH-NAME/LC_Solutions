#!/bin/python3

from typing import List, Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def inorder(self, root: Optional[TreeNode], arr: List[int]) -> None:
        if not root:
            return
        self.inorder(root.left, arr)
        arr.append(root.val)
        self.inorder(root.right, arr)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result: List[int] = []
        self.inorder(root, result)
        return result

def build_tree(data: str) -> TreeNode:
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
        "1,null,2,3",
        "1,2,3,4,5,null,8,null,null,6,7,9",
        "",
        "1",
    ]

    for tc in tests:
        head = build_tree(tc)
        print(f"---\nList: [{tc}]\nresult: {Solution().inorderTraversal(head)}")

if __name__ == "__main__":
    main()
