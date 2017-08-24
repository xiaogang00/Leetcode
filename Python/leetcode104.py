class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def maxDepth(self, root):

        def maxDepthHelper(root):
            if not root: return 0
            return max(1+maxDepthHelper(root.left), 1+maxDepthHelper(root.right))

        return maxDepthHelper(root)
