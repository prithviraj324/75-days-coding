#include<bits/stdc++.h>
using namespace std;
//initial soln, 12% time, 5% space BCZ dp soln
//O(n2) soln
class Solution {
public:
    bool solve(vector<int>& dp, vector<int>& nums, int pos) {
        //base conds
        if(pos>nums.size() - 1) return false;
        if(dp[pos] != -1) return (bool)dp[pos];
        //greedy approach
        for(int i=nums[pos];i>0;i--) {
            if(pos+i > nums.size()-1)
                continue;
            bool t =solve(dp, nums, pos+i);
            if(t) {
                dp[pos] = (int)t;
                return t;
            }
        }
        dp[pos]=0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);    //-1 default, 1->can reach end, 0->cant reach
        dp[nums.size()-1] = 1;
        
        return solve(dp, nums, 0);
    }
};

//proper soln: using greedy approach
//moving end point closer by computing closest index where goal is reachable and moving goal to that index
//O(n) solution

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;   //goal idx
        int prev=goal-1;
        if(goal==0) return true;
        while(prev >= 0) {
            if(nums[prev] >= goal-prev) {
                goal=prev;
                prev=goal-1;
            }
            else 
                prev--;
        }
        return goal==0 ? 1 : 0;
    }
};