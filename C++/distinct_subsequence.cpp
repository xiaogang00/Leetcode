//
// Created by Theo on 2017/10/31.
//

class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.empty())
            return 0;
        if(t.empty())
            return 1;
        vector<vector<int> > dp(s.length() + 1, vector<int>(t.length() + 1));
        dp[0][0] = 1;
        for(int i = 1; i <= s.length(); i++)
            dp[i][0] = 1;
        for(int i = 1; i <= t.length(); i++)
            dp[0][i] = 0;
        for(int i = 1; i <= s.length(); i++) {
            for(int j = 1; j <= t.length(); j++) {
                if(s[i - 1] != t[j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[s.length()][t.length()];
    }
};