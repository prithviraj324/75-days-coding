#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(vector<int> p, vector<int> q) {
        return p[1] > q[1];
    }
    int maximumUnits(vector<vector<int>>& boxes, int tsize) {
        sort(boxes.begin(), boxes.end(), compare);
        int n=boxes.size();
        int i=0;
        for(auto v: boxes) {
            if(tsize <= 0) break;
            if(tsize >= v[0]) {
                i += v[0]*v[1];
                tsize -= v[0];
            }
            else if(tsize < v[0]) {
                i += tsize*v[1];
                break;
            }
        }
        return i;
    }
};