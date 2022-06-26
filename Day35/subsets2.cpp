#include<bits/stdc++.h>
using namespace std;
//good question
//involves pruning `duplicate-subset generating` paths of the exponential tree trraversed in subsets1 problem
class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, int i, vector<int>& x) {
        if(i>=nums.size()) {
            ans.push_back(x);
            return;
        }
        //trick is, case 1: first include the set of duplicates into nums[i]
        //this will create the first of the duplicates of the subsets to be made, we'll keep them as og ones
        //next, case 2: we dont just exclude the current nums[i] but we exclude the entire set of duplicates of nums[i]
        //this ensures that we dont end up creating duplicates of subsets made by case 1.
        //algo enumerated ->
        
        //subsets that include nums[i] ->
        x.push_back(nums[i]);
        dfs(ans, nums, i+1, x);
        x.pop_back();
        //usual stuff
        
        //subsets that exclude nums[i] ->
        while(i+1 < nums.size() && nums[i]==nums[i+1])
            i++;
        dfs(ans, nums, i+1, x);
        //basically exculde the entire group of nums[i] that have same value
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); //sorting to group duplicates, max size of nums is 10 so sorting is insignificant
        vector<int> temp;
        dfs(ans, nums, 0, temp);
        return ans;
    }
};