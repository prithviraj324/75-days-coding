#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0,r=1;
        int n=nums.size();
        while(l<r && r<n) {
            if(nums[l]!=0 && nums[r]!=0) {//1,2
                l+=2;
                r+=2;
            }
            else if(nums[l]==0 && nums[r]==0)//0,0
                r=r+1;
            else if(nums[l]==0 && nums[r]!=0) {//0,3
                nums[l]=nums[r];
                nums[r]=0;
                l++;
                r=r+1;
            }
            else {//3,0
                l++;
                r=r+1;
            }
        }
    }
};