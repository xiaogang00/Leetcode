//
// Created by Theo on 2017/4/9.
//

class Solution {
public:
    int uniquePaths(int m, int n) {
        int s[n];
        // 第一行全为1
        for(int i = 0;i < n;++i){
            s[i] = 1;
        }//for
        // 从第二行开始
        for(int i = 1;i < m;++i){
            // 第i行第j个格
            for(int j = 1;j < n;++j){
                s[j] = s[j] + s[j-1];
            }//for
        }//for
        return s[n-1];
    }
}