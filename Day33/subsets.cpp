#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, int i, vector<int>& x) {
        if(i>=nums.size()) {
            ans.push_back(x);
            return;
        }
        dfs(ans, nums, i+1, x);
        x.push_back(nums[i]);
        dfs(ans, nums, i+1, x);
        x.pop_back();//backtracking
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(ans, nums, 0, temp);
        return ans;
    }
};