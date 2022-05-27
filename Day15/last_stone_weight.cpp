#include<bits/stdc++.h>
using namespace std;
//first solution would be sorting, choose last 2, insert big-small 
//inserting big-small and then again sorting the new array takes n2logn time
//hence use maxheap of size n,
//code is readable
//tc:O(nlogn), sc:O(n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];
        int x,y;
        
        priority_queue<int> maxh(stones.begin(),stones.end());
        while(maxh.size() > 1) {
            x=maxh.top();
            maxh.pop();
            y=maxh.top();
            maxh.pop();
            if(x != y) maxh.push(x-y);
        }
        return maxh.empty() ? 0 : maxh.top();
    }
};