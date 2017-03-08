#include <vector>
#include <iostream>
using namespace std;
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  static bool comp(const Interval& a, const Interval& b){
        return a.start < b.start;
    }

  vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty()){
            return result;
        }
        sort(intervals.begin(), intervals.end(), comp); //依照vector来进行排序
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start <= result.back().end){
                Interval temp(result.back().start, max(result.back().end, intervals[i].end));
                result.pop_back();
                result.push_back(temp);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;

    }
};