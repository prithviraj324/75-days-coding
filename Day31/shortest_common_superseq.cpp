#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int solve(string x, string y, vector<vector<int>>& dp, int m, int n) {
        if(dp[m][n] != -1) return dp[m][n];
        if(x[m-1] == y[n-1])
            return dp[m][n] = 1 + solve(x, y, dp, m-1, n-1);
        else
            return dp[m][n] = max(solve(x, y, dp, m-1, n), solve(x, y, dp, m, n-1));
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        dp[0]=vector<int>(n+1, 0);
        for(int i=0;i<m+1;i++)
            dp[i][0]=0;
    
        int lcs=solve(X, Y, dp, m, n);
        return m+n-lcs;
    }
};