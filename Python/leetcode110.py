class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True

        elif (abs(self.height(root.left) - self.height(root.right)) >= 1):
            return False
        else:
            return (self.isBalanced(root.left) and self.isBalanced(root.right))


    def height(self, root):
        """
        :param root: TreeNode
        :return: int
        """
        if root is None:
            return 0
        elif (root.left is None and root.right is None):
            return 1
        elif root.right is None:
            return 1 + self.height(root.left)
        elif root.left is None:
            return 1 + self.height(root.right)
        else:
            return 1 + max(self.height(root.left), self.height(root.right))