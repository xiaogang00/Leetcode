//
// Created by Theo on 2017/7/18.
//

struct Interval{
    int start;
    int end;
    Interval() : start(0), end(0){}
    Interval(int s, int e) : start(s), end(e){}
};

class Solution{
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
        vector<Interval> vi;
        int i = 0;
        while(i < intervals.size() && intervals[i].end < newInterval.start)
            vi.push_back(intervals[i ++]);
        vi.push_back(newInterval);
        while(i < intervals.size() && vi[vi.size() - 1].end >= intervals[i].start)
        {
            vi[vi.size() - 1].start = min(intervals[i].start, vi[vi.size() - 1].start);
            vi[vi.size() - 1].end = max(intervals[i].end, vi[vi.size() - 1].end);
            ++ i;
        }
        while(i < intervals.size())
            vi.push_back(intervals[i++]);
        return vi;
    }
};