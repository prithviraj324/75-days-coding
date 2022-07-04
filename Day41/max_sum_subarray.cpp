#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //kadane's algo
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int maxsum=INT_MIN, cursum=0;
        for(int i=0;i<nums.size();i++)  {
            if(cursum < 0) cursum = 0;
            cursum += nums[i];
            maxsum=max(maxsum, cursum);
        }
        
        return maxsum;
    }
};