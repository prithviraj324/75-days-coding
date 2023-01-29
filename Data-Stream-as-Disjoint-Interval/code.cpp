#include <bits/stdc++.h>
using namespace std;
class SummaryRanges {
public:
    set<int> arr;
    SummaryRanges() {
        arr = {};
    }
    
    void addNum(int val) {
        arr.insert(val);
        return;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        if(arr.size() == 1) {
            return {{*arr.begin(), *arr.begin()}};
        }
        int prev = *arr.begin();
        int l = prev, r = prev;
        auto i = arr.begin();
        i++;
        for(; i!= arr.end(); i++) {
            if(*i == prev + 1) {
                r = *i; //nxt in order
                prev = *i;  //update prev
                continue;
            }
            else {
                res.push_back({l,r});  //interval ended
                l = *i; //set new left num
                r = *i; //set new right num (for trailing intervals)(think arr = 1,2,3,6)
                prev = *i; //set new prev
                continue;
            }
        }//for
        res.push_back({l,r});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */