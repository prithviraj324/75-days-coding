#include<bits/stdc++.h>
using namespace std;
//jump game, but here we know end goal is reachable
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int steps=0;    //no of bfs done i.e no of steps taken
        for(int i=0;i<n;i++) 
            nums[i]+=i;
        
        //bfs of levels
        int l=0, r=0, mini=INT_MAX, maxi=INT_MIN;
        while(r<n) {
            if(r == n-1) return steps;
            //cout<<"left:"<<l<<", right:"<<r<<endl;
            for(;l<=r;l++) {
                maxi=max(maxi, nums[l]);
                mini=min(mini, nums[l]);
            }
            l=r+1;
            r=maxi;
            ++steps;
        }
        return steps;
    }
};