//
// Created by Theo on 2017/8/10.
//

class Solution {
public:
    int numTrees(int n) {
        vector<int> result;
        result.push_back(1);
        result.push_back(1);
        //二叉查找树种类总数是以所有结点为根的可行结果累加起来
        for(int i = 2; i <= n; i++)
        {
            int sum = 0;
            //计算含i个结点时二叉查找树的种类数，j表示1~i中取任一结点作为根。
            for(int j = 1; j <= i; j++)
            {
                sum += (result[j-1] * result[i-j]);   //左树*右树  实现递推公式
            }

            result.push_back(sum);
        }

        return result.back();
    }
};