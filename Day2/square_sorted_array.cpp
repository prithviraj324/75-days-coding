#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        deque<int> dq;
        int m;
        int l=0,r=nums.size()-1;
        while(l<=r){
            m=max(nums[l]*nums[l],nums[r]*nums[r]);
            dq.push_front(m);
            if(m==nums[l]*nums[l])
                l++;
            else
                r--;
        }
        vector<int> v(dq.begin(),dq.end());
        return v;
    }
};