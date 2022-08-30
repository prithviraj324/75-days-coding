#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        vector<int> LIS(n, 1);
        int res = INT_MIN;
        
        for(int i=n-2;i>=0;i--) {
            for(int j = i;j<n;j++) {
                if(nums[i] < nums[j])
                    LIS[i] = max(LIS[i], 1+LIS[j]);
                else continue;
            }
            res = max(res, LIS[i]);
        }
        return res;
    }
};