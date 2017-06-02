//
// Created by Theo on 2017/6/2.
//

#include <vector>
#include <table>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        vector<int> table(grid[0].size(), 0);
        for(int i = 0 ; i < grid[0].size(); i++)
        {
            if(i==0)
                table[i] = grid[0][0];
            else
                table[i] = table[i-1]+grid[0][i];
        }
        if(grid.size()>1)
            for(int i=1; i<grid.size(); i++)
            {
                table[0] = table[0]+grid[i][0];

                if(grid[0].size()>1)
                    for(int j=1; j<grid[0].size(); j++)
                    {
                        table[j] = grid[i][j] + min(table[j-1], table[j]);
                    }
            }

        return table.back();
    }
};