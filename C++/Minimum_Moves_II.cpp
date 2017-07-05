//
// Created by Theo on 2017/7/5.
//
class Solution{
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
        int min = nums[0];
        for (int i:nums) min = min < i ? min : i;
        for (int i:nums) count += i - min;
        return count;
    }
};
