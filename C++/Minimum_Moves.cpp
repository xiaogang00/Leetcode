//
// Created by Theo on 2017/7/5.
//

class Solution{
public:
    //主要是计算数组的中位数，并且依据这个进行
    int minMoves2(vector<int>& nums) {
        int count = 0;
        if (nums.size() == 0) return count;
        sort(nums.begin(),nums.end());
        int midNum = nums[nums.size()/2];
        //寻找中位数
        for (int i = 0;i<nums.size();i++) {
            count += abs(midNum - nums[i]);
        }
        return count;
    }
};