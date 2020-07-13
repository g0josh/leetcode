from typing import Union, List
import math

class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def createBST(nums:List[Union[int, str]]) -> TreeNode:
    def temp(index):
        if index < len(nums):
            t = TreeNode(nums[index])
            t.left = temp(2*index+1)
            t.right = temp(2*index+2)
            return t
        else:
            return None

    return temp(0)

def isValidBST(root: TreeNode) -> bool:
    if not root:
        return True

    def temp(root, lower, higher):
        if root is None or root.val is None:
            return True
        if root.val <= lower or root.val >= higher:
            return False
        return temp(root.left, lower, root.val) and temp(root.right, root.val, higher)

    return temp(root, float('-inf'), float('inf'))


def maxDepth(root: TreeNode) -> int:
    if root is None or root.val is None:
        return 0

    return max(maxDepth(root.left), maxDepth(root.right)) + 1


def isSymmetric(root: TreeNode) -> bool:
    if root is None or root.val is None:
        return True
    def temp(t1, t2):
        if (t1 is None and t2 is None): return True
        if None in [t1, t2] or t1.val != t2.val: return False
        if t1.val == t2.val:
            return temp(t1.left, t2.right) and temp(t1.right, t2.left)
    return temp(root.left, root.right)

def levelOrder(root: TreeNode) -> List[List[int]]:
    result = {}
    def temp(node, index):
        nonlocal result
        if node is None or node.val is None:
            return
        if index in result:
            result[index].append(node.val)
        else:
            result[index] = [node.val]
        temp(node.left, index + 1)
        temp(node.right, index + 1)
    temp(root, 0)
    return [result[i] for i in range(len(result))]

def sortedArrayToBST(nums: List[int]) -> TreeNode:
    def temp(start, end):
        if start == end:
            return None
        mid = start + math.floor((end-start)/2)
        t = TreeNode(nums[mid])
        t.left = temp(start, mid)
        t.right = temp(mid+1, end)
        return t
    return temp(0, len(nums))

if __name__ == "__main__":
    bst = createBST([3,1,5,0,2,4,6,None,None,None, 3])
    # bst = createBST([0, None, -1])
    # bst = createBST([2,1,3])
    # print(isValidBST(bst))
    # print(maxDepth(bst))

    # bst = createBST([1,2,2,3,4,4,3])
    # bst = createBST([1,2,2,None,3,None,3])
    # print(isSymmetric(bst))

    # bst = createBST([3,9,20,None,None,15,7])
    print(levelOrder(bst))

    # s = sortedArrayToBST([-10,-3,0,5,9])