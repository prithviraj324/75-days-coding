//VERY HIGH TIME AND SPACE (5% AND 5%)
//TC-NLOGN,SC-N
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool compi(vector<int> v1,vector<int> v2) {
        return v1[0]<v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end(),compi);
        int start=intervals[0][0],end=intervals[0][1];
        int i=1;
        if(intervals.size()==1)
            return intervals;
        
        while(i<intervals.size()) {
            if(intervals[i][0]<=end) {
                end=max(end,intervals[i][1]);
                i++;
            }
            else {
                res.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
                i++;
            }
            if(i==intervals.size()) {
                res.push_back({start,end});
            }
        }
        return res;
    }
};