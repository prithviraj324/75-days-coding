#include<bits/stdc++.h>
using namespace std;
//initial brute force with basic pruning, i.e if cand[i] > target, dont go down that path
//no backtracking, just blind recursion
class Solution {
public:
    map<vector<int>, int> m;
    void dfs(vector<vector<int>>& ans, vector<int>& cand, int i, int target, vector<int> temp) {
        if(i<cand.size() && target == 0) {
            if(m.find(temp) == m.end()) {
                ans.push_back(temp);
                m.insert({temp, 1});
                return;    
            }
            else return;
        }
        else if(i>=cand.size()) return;
        dfs(ans, cand, i+1, target, temp);
        if(cand[i] <= target) {
            temp.push_back(cand[i]);
            dfs(ans, cand, i, target-cand[i], temp);
            dfs(ans, cand, i+1, target-cand[i], temp);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(ans, cand, 0, target, temp);
        return ans;
    }
};

//way faster solution, actually using backtracking on top of brute force recursion
class Solution {
public:
    map<vector<int>, int> m;
    void dfs(vector<vector<int>>& ans, vector<int>& cand, int i, int target, vector<int>& temp) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(i==cand.size()) return;
        if(target < 0) return;

        dfs(ans, cand, i+1, target, temp);
        temp.push_back(cand[i]);
        dfs(ans, cand, i, target-cand[i], temp);
        //have not made call with i+1 as in the next call, it will anyways call with i+1 as seen in line 45
        temp.pop_back();//********* ESSENCE OF BACKTRACKING, WE BACKTRACK TO STATE WHERE CAND[I] WASNT PUSHED INTO TEMP
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(ans, cand, 0, target, temp);
        return ans;
    }
};