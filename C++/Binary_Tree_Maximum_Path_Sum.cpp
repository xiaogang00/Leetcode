//
// Created by Theo on 2017/11/3.
//

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    int maxPathSum(TreeNode *root) {
        int res = root->val;
        maxPathSumDFS(root, res);
        return res;
    }
    int maxPathSumDFS(TreeNode *root, int &res) {
        if (!root) return 0;
        int left = maxPathSumDFS(root->left, res);
        int right = maxPathSumDFS(root->right, res);
        int top = root->val + (left > 0 ? left : 0) + (right > 0 ? right : 0);
        res = max(res, top);
        return max(left, right) > 0 ? max(left, right) + root->val : root->val;
    }
};