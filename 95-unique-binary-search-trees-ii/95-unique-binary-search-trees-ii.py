# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        if n==0:
            return []
        def helper(start,end):
            if start>end:
                return [None]
            result=[]
            for cur_root in range(start,end+1):
                all_left_bst=helper(start,cur_root-1)
                all_right_bst=helper(cur_root+1,end)
                for left_bst in all_left_bst:
                    for right_bst in all_right_bst:
                        curr=TreeNode(cur_root)
                        curr.left=left_bst
                        curr.right=right_bst
                        result.append(curr)
            return result
        return helper(1,n)