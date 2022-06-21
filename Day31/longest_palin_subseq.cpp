#include<bits/stdc++.h>
using namespace std;
//brute force, gives tle, use for reference to build table 
class Solution{
    public:
    int solve(/*vector<vector<int>>& dp, */string& s, int i, int j) {
        if(i<0 || j<0 || i>=s.size() || j>=s.size()) return 0;
        
        if(s[i] == s[j] && i == j)
            return 1 + solve(s, i-1, j+1);
        else if(s[i] == s[j] && i != j)
            return 2 + solve(s, i-1, j+1);
        else
            return max(solve(s, i-1, j), solve(s, i, j+1));
    }
    int longestPalinSubseq(string A) {
        //code here
        int n=A.size();
        //if(n==1)
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        // int x=solve(dp, A, n, n);
        int maxi=0;
        for(int i=0;i<n;i++) {
            maxi=max(maxi, max(solve(A, i, i), solve(A, i, i+1)));
        }
        return maxi;
    }
};
//top down memoized -> 

class Solution{
    public:
    int solve(vector<vector<int>>& dp, string& s, int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i-1] == s[j-1] && i == j)
            return dp[i][j] = 1 + solve(dp, s, i-1, j+1);
        else if(s[i-1] == s[j-1] && i != j)
            return dp[i][j] = 2 + solve(dp, s, i-1, j+1);
        else
            return dp[i][j] = max(solve(dp, s, i-1, j), solve(dp, s, i, j+1));
    }
    int longestPalinSubseq(string A) {
        //code here
        int n=A.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        for(int i=0;i<n+2;i++) {
            dp[i][0]=0;
            dp[i][n+1]=0;
            dp[0][i]=0;
            dp[n+1][i]=0;
        }
        int maxi=0;
        for(int i=1;i<n+1;i++) {
            maxi=max(maxi, max(solve(dp, A, i, i), solve(dp, A, i, i+1)));
        }
        return maxi;
    }
};