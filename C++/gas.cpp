//
// Created by Theo on 2017/9/23.
//

class Solution {
public:
    //O(n)的解法是遍历所有站点，用sum记录当前选择的出发点的有效性
    // 用total来判断整个数组是否有解，有解的话返回sum所在下标
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int total = 0;
        int start_index = -1;
        for(int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];

            if(sum < 0) {
                sum = 0;
                start_index = i;
            }
        }
        return total >= 0 ? start_index + 1 : -1;
    }
};