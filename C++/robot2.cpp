//
// Created by Theo on 2017/4/9.
//
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector< vector<int> >  result(m+1);
        for(int i=0;i <=m ;i++)
            result[i].resize(n+1);//设置数组的大小m+1行，n+1列
        //初始化一定要正确，否则错无赦
        result[1][1]= obstacleGrid[0][0]==1? 0:1;
        for(int i=2;i<=n;i++)
            result[1][i]=obstacleGrid[0][i-1]==1?0:result[1][i-1];//由上一次来推到
        for(int i=2;i<=m;i++)
            result[i][1]=obstacleGrid[i-1][0]==1?0:result[i-1][1];

        for(int i=2;i<=m;i++)
            for(int j=2;j<=n;j++)
                result[i][j]=obstacleGrid[i-1][j-1]==1?0:result[i-1][j]+result[i][j-1];  //一旦当前有石头就无法到达，直接置零

        return result[m][n];
    }
};