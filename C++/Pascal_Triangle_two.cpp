//
// Created by Theo on 2017/9/8.
//

//The first method is to compute row by row
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,1);
        if(rowIndex<2)
            return result;
        for(int i=2;i<=rowIndex;i++){
            for(int j=i-1;j>0;j--){
                result[j]+=result[j-1];
            }
        }
        return result;
    }
};

// The second method is result[i]=result[i-1]*(rowIndex-i+1)/i

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,0);
        result[0]=result[rowIndex]=1;
        for(int i=1;i<=rowIndex/2;i++){
            result[i]=result[rowIndex-i]=(unsigned long)result[i-1]*(rowIndex-i+1)/i;
        }
        return result;
    }
};