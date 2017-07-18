//
// Created by Theo on 2017/7/18.
//

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        int max_size=0;
        int index=0;
        int *s=(int*)malloc(sizeof(int)*heights.size());
        int stack_index=0;

        while(index<heights.size())
        {
            if(stack_index==0||heights[s[stack_index-1]]<=heights[index])
            {
                s[stack_index++]=index;
                index++;
            }
            else
            {
                int top=s[--stack_index];
                int size=0;

                if(stack_index==0)
                {
                    size=heights[top]*index;
                }
                else
                {
                    size=heights[top]*(index-s[stack_index-1]-1);
                }

                if(size>max_size) max_size=size;
            }
        }

        free(s);

        return max_size;
    }
};