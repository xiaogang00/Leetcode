//
// Created by Theo on 2017/8/10.
//

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        TreeNode* pre = NULL;
        return in_order(root, pre);
    }

private:
    bool in_order(TreeNode* node, TreeNode* &pre)
    {
        if(node == NULL)
            return true;

        if(!in_order(node->left, pre)) return false;
        if(pre != NULL && pre->val >= node->val) return false;
        pre = node;
        return in_order(node->right, pre);
    }
};