#include<bits/stdc++.h>
using namespace std;
//----------------------------------------------------------------
//brute force exponention top down Solution
//TLE
//----------------------------------------------------------------
class Solution {
public:
    int steal(vector<int>& arr, int pos, int end) {
        if(pos>end) return 0;
        else 
            return max(arr[pos]+steal(arr,pos+2,end), steal(arr, pos+1, end));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(steal(nums, 0, nums.size()-2),steal(nums, 1, nums.size()-1));
    }
};
//----------------------------------------------------------------
//memoized above solution->
//----------------------------------------------------------------
class Solution2 {
public:
    int steal(vector<int>& dp, vector<int>& arr, int pos, int end) {
        if(dp[pos] != -1) return dp[pos];
        if(pos>end) return 0;
        else {
            int a=arr[pos]+steal(dp, arr,pos+2,end);
            int b=steal(dp, arr, pos+1, end);
            return dp[pos]=max(a,b);
        }
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size()+2,-1);
        //when steal(pos=end of nums) is called, following 2 indices are needed to compute
        dp[nums.size()+1]=0;
        dp[nums.size()]=0;
        int a=steal(dp, nums, 0, nums.size()-2);
        dp=vector<int>(nums.size()+2,-1);//need 2 dp arrays as first run might corrupt data corresponding to 2nd run
        int b=steal(dp, nums, 1, nums.size()-1);
        return max(a,b);
    }
};
//same solution using constant space->
class Solution3 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        //houses are in this order: 'pre'->'cur'->'temp i.e nums[i]'
        //instead of adding 2 dummy entries in dp vector, we start from beginning here
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            //we can reach temp by either robbing pre and then landing on temp (ie robbedAmt=pre+nums[i])
            int temp = max(pre + nums[i], cur);
            //houses become like:
            //  pre->cur->temp->nums[i+1]->...
            //     shift->by->1
            //       pre->_cur->temp->nums[i+1]->...
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};