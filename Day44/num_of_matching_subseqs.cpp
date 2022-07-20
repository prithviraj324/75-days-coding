#include<bits/stdc++.h>
using namespace std;


//kind of a brute force solution, for each
class Solution {
public:
    int lcs(vector<vector<int>>& dp, string x, string y, int i, int j) {
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(x[i] == y[j])
            return dp[i][j] = 1 + lcs(dp, x, y, i-1, j-1);
        else
            return dp[i][j] = max(lcs(dp, x, y, i-1, j), lcs(dp, x, y, i, j-1));
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int r = s.size(), ans = 0;
        for(string w: words) {
            int c = w.size();
            vector<vector<int>> dp(r, vector<int>(c,-1));
            if(lcs(dp, s, w, r-1, c-1) == c)
                ans++;
        }
        
        return ans;
    }
};

//storing previously computed subseq's if any repetition occurs, helps in clearing tc 11     
class Solution2 {
public:
    unordered_map<string, int> mp;
    int lcs(vector<vector<int>>& dp, string x, string y, int i, int j) {
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(mp.find(x+y) != mp.end()) return mp[x+y];
        
        if(x[i] == y[j]) {
            dp[i][j] = 1 + lcs(dp, x, y, i-1, j-1);
            return mp[x+y] = dp[i][j];
        }
        else {
            dp[i][j] = max(lcs(dp, x, y, i-1, j), lcs(dp, x, y, i, j-1));
            return mp[x+y] = dp[i][j];
        }
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int r = s.size(), ans = 0;
        for(string w: words) {
            int c = w.size();
            vector<vector<int>> dp(r, vector<int>(c,-1));
            if(lcs(dp, s, w, r-1, c-1) == c)
                ans++;
        }
        
        return ans;
    }
}; //gives tle at tc12 :/

//another solution that traverses each string in words[] as each char in S is encountered
//TC: O(n*length of longest string in words[])
class Solution3 {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size(), ans = 0;
        vector<int> pos(n, 0);//stores idx of character the word is waiting for, all wait for first chaarcter
        
        for(char c : s) {
            for(int i=0;i<n;i++) {
                if(pos[i] == -1) continue;
                if(words[i][pos[i]] == c)
                    pos[i]++;
                if(pos[i] == words[i].size()) {
                    ans++;
                    pos[i]=-1;
                }
            }
        }
        return ans;
    }
};

//below solution is proper, no tle, very good time and space %'s
//need to redo
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<pair<int, int>> waiting[128];
        for (int i = 0; i < words.size(); i++)
            waiting[words[i][0]].emplace_back(i, 1);
        for (char c : S) {
            auto advance = waiting[c];
            waiting[c].clear();
            for (auto it : advance)
                waiting[words[it.first][it.second++]].push_back(it);
        }
        return waiting[0].size();
    }
};