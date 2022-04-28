#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prev,lsum=0,rsum=0;
        for(int x=0;x<nums.size();x++)
            rsum+=nums[x];
        rsum-=nums[0];
        for(int i=0;i<nums.size();i++) {
            prev=nums[i];
            if(rsum==lsum)
                return i;
            else if(i!=nums.size()-1) {
                rsum-=nums[i+1];
                lsum+=prev;
            }
        }
        return -1;
    }
};