//
// Created by Theo on 2017/9/26.
//

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> set1;
        for (auto i : wordDict) {
            set1.insert(i);
        }
        int len = s.size();
        bool dp[len+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for (int i=1; i<=len; i++) {
            for (string sub : set1) {
                if (sub.size() <= i) {
                    if (dp[i - sub.size()]) {
                        if (sub == s.substr(i-sub.size(), sub.size())) {
                            dp[i] = true;
                            break;
                        }
                    }

                }
            }
        }
        return dp[len];
    }
};