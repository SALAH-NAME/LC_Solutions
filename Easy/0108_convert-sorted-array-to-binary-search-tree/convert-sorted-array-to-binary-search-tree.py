#!/bin/python3

from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildBalanceBST(self, nums: List[int], start: int, end: int) -> Optional[TreeNode]:
        if start > end:
            return None
        mid = (start + end) // 2
        node = TreeNode(nums[mid])
        node.left = self.buildBalanceBST(nums, start, mid - 1)
        node.right = self.buildBalanceBST(nums, mid + 1, end)
        return node
        
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.buildBalanceBST(nums, 0, len(nums) - 1)

def printTree(node: TreeNode) -> None:
    if not node:
        return
    printTree(node.left)
    print(node.val,end=' -> ')
    printTree(node.right)

def main():
    tests: List[List[int]]=[
        [-10,-3,0,5,9],
        [1,3],
    ]

    for tc in tests:
        print(f"---\nnums={tc}")
        tree: TreeNode = Solution().sortedArrayToBST(tc)
        printTree(tree)
        print("None")

if __name__ == "__main__":
    main()
