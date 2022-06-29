#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int , string> m = {{2,"abc"},
                                     {3,"def"},
                                     {4,"ghi"},
                                     {5,"jkl"},
                                     {6,"mno"},
                                     {7,"pqrs"},
                                     {8,"tuv"},
                                     {9,"wxyz"}
                                    };
    void dfs(string& s, int i, string& temp, vector<string>& ans) {
        int n = s.length();
        if(i == n) {
            ans.push_back(temp);
            return;
        }
        
        int num = (int)(s[i] - '0');
        for(char c: m[num]) {
            temp.push_back(c);
            dfs(s, i+1, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        if(digits.size() == 0) 
            return {};
        
        dfs(digits, 0, temp, ans);
        return ans;
    }
};