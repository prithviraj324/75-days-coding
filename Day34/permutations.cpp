#include<bits/stdc++.h>
using namespace std;
//brute force exponential solution
class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp, unordered_set<int>& s) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for(int x=0;x<nums.size();x++) {
            if(s.find(x) != s.end()) continue;
            temp.push_back(nums[x]);
            s.insert(x);
            dfs(ans, nums, temp, s);
            temp.pop_back();
            s.erase(x);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.clear();
        if(nums.size() == 1) {
            ans.push_back(nums);
            return ans;
        }
        unordered_set<int> s;
        vector<int> temp;
        dfs(ans, nums, temp, s);
        
        return ans;
    }
};
//faster solution, but same time complexity
//instead of staring a set s of all used elements, bring the used element to the prefix subarray of nums given by nums[0...i]
//run dfs on nums[i...n]
//reduces space taken for maintaining set s and reduces iteration time in average case as we are iterating over postfix subarrays
class Solution2 {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
};