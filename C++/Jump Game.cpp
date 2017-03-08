#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int reach=0;
        for(int i=0;i<=reach && i<n;i++){
            reach=max(nums[i]+i,reach);
        }

        if(reach < n-1)
            return false;
        return true;
    }
};