//
// Created by Theo on 2017/8/19.
//

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if(s.size() == 0) return ret;
        vector<string> tmp;
        partition_helper(s, tmp, ret);
        return ret;
    }

private:
    void partition_helper(string s, vector<string> tmp, vector<vector<string>>& ret)
    {
        if(s.size() == 0)
        {
            ret.push_back(tmp);
            return;
        }

        for(int i = 1; i <= s.size(); i++)
        {
            string substr = s.substr(0, i);
            if(isPalindrome(substr))
            {
                int strlen = s.size();
                tmp.push_back(substr);
                partition_helper(s.substr(i, strlen - i), tmp, ret);
                tmp.pop_back();
            }
        }
    }

    //假设不含空格等其他字符，只含小写字母
    bool isPalindrome(string s)
    {
        int len = s.size();
        if(len == 0 || len == 1) return true;
        int i = 0;
        int j = len - 1;

        while(i < j)
        {
            if(s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }
};