#include<bits/stdc++.h>
using namespace std;
//----------------------------------------------------------------
//k closest ie k least distances from origin
//hence use maxheap with custom comparator, syntax below
//TC:O(nlogk), SC:O(2n) bcz result array is inevitable
//--------------------------------------------------------------
class Solution {
public:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for(auto pt:points) {
            pq.push(pt);
            if(pq.size() > k)
                pq.pop();
        } 
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};