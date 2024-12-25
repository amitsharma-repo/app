#include<merge_interval.h>
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const vector<int>& x, const vector<int>& y){
            return x[0] < y[0];
    });
    vector<vector<int>> returnVec;
    vector<int> interval = intervals[0];
    auto it = intervals.begin(); ++it;
    bool bIntervalEnd = false;
    while(true)
    {
        if(it == intervals.end())
        {
            returnVec.push_back(interval);
            break;
        }
        if (interval[1]  >= (*it)[0])
        {
            if(interval[1] <= (*it)[1])
            {
                interval[1] = (*it)[1];
            }
            else
            {
                ++it;
                continue;
            }
        }
        else
        {

            returnVec.push_back(interval);
            interval = *it;
        }
        ++it;
    }
    return returnVec;
}
