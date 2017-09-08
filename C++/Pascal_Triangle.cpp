//
// Created by Theo on 2017/9/8.
//

//仔细观察可以发现规律：tri[i][j] = tri[i-1][j-1] + tri[i-1][j]。

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if(numRows == 0)
            return vector<vector<int> >(0);

        vector<vector<int> > ivec;
        int i = 0, j = 0;
        for(i = 0; i < numRows; i++) {
            vector<int> vec;
            for(j = 0; j < i+1; j++) {
                if(j == 0 || j == i)
                    vec.push_back(1);
                else
                    vec.push_back(ivec[i-1][j-1] + ivec[i-1][j]);
            }
            ivec.push_back(vec);
        }
        return ivec;
    }
};