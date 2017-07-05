//
// Created by Theo on 2017/7/5.
//

class Solution
{
 public:
     vector<int> plusOne(vector<int> &digits)
     {
         // 从后往前，碰到第一个不是9的就对其加1，然后返回即可
         for(int i = digits.size() - 1; i >= 0; -- i)
         {
             if(digits[i] == 9)
                 digits[i] = 0;
             else
             {
                 ++ digits[i];
                 return digits;
             }
         }
         // 最高位改成1，最后再添加个0
         digits[0] = 1;
         digits.push_back(0);
         return digits;
     }
};