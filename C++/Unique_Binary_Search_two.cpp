//
// Created by Theo on 2017/8/10.
//

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0)
        {
            return generateTrees_helper(1, 0);
        }
        return generateTrees_helper(1, n);
    }

private:
    vector<TreeNode*> generateTrees_helper(int start, int end)
    {
        vector<TreeNode*> trees;
        if(start > end)
        {
            trees.push_back(NULL);
            return trees;
        }

        if(start == end)
        {
            trees.push_back(new TreeNode(start));
            return trees;
        }

        for(int i = start; i <= end; i++)
        {
            //产生以i为根结点的左右子树的所有可能。i取值start到end
            vector<TreeNode*> leftTree = generateTrees_helper(start, i-1);
            vector<TreeNode*> rightTree = generateTrees_helper(i+1, end);

            //将左子树的所有可能和右子树的所有可能连接.leftTree[0]表示第一个节点。
            for(int j = 0; j < leftTree.size(); j++)
            {
                for(int k = 0; k < rightTree.size(); k++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    trees.push_back(root);  //trees保存当前的根结点
                }
            }
        }

        return trees;
    }
};