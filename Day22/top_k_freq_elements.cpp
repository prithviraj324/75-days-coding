#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return q[1] < p[1];
        }//minheap comparator
        //We will return true for what type of order we want to maintain. The order will be seen from bottom to top.
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        //inserting a pair of ints into pq, where pair[0]=element, p[1]=frequency in arr
        priority_queue<vector<int>, vector<vector<int>>, compare> minh;
        
        unordered_map<int,int> m;   //map # to its frequency
        for(auto i:nums) {
            if(m.find(i)==m.end())  m.insert({i,1});
            else m[i]++;
        }
        
        for(auto pair:m) {  //for each pair of (num,freq)
            minh.push({pair.first, pair.second});
            if(minh.size()>k)
                minh.pop();
        }
        
        while(!minh.empty()) {
            v.push_back(minh.top()[0]);
            minh.pop();
        }
        return v;
    }
};