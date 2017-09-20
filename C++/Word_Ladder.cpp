//
// Created by Theo on 2017/9/20.
//

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int dis=1;
        int len=wordList.size();
        int *visit=new int[len];
        memset(visit,0,len*sizeof(int));

        queue<string> q;
        for (int i=0; i<len; i++)
        {
            if (cmpStr(beginWord, wordList[i])==true)
            {
                if (wordList[i] == endWord) return 2;
                q.push(wordList[i]);
                visit[i]=1;
            }

        }
        if (q.empty()) return 0;
        dis++;
        while (!q.empty())
        {
            int _siz=q.size();
            while (_siz)
            {
                string tmp(q.front());
                if (tmp == endWord) return dis;
                for (int i=0; i<len; i++)
                {
                    if (!visit[i])
                    {
                        if (cmpStr(tmp, wordList[i]))
                        {
                            if (wordList[i] == endWord) return dis+1;
                            q.push(wordList[i]);
                            visit[i]=1;
                        }
                    }
                }
                q.pop();
                _siz--;
            }
            dis++;
        }
        return 0;
    }

    bool cmpStr(string s1, string s2)
    {
        int len=s1.size();
        int diff=0;
        for (int i=0; i<len; i++)
        {
            if (s1[i] != s2[i])
            {
                diff++;
            }
        }
        if (diff == 1) return true;
        else return false;
    }
};