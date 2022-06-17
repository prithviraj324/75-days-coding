#include<bits/stdc++.h>
using namespace std;
//brute force exponential solution
class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string S1, string S2)
    {
        if(n==0 || m==0) return 0;
        if(S1[n-1] == S2[m-1])
            return 1 + lcs(n-1, m-1, S1, S2);
        else
            return max(lcs(n-1, m, S1, S2), lcs(n, m-1, S1, S2));
    }
};
//top down memoized function
class Solution2
{
public:
    int solve(vector<vector<int>>& dp, string s1, string s2, int n, int m) {
        if(dp[n][m] != -1)  return dp[n][m];
        if(s1[n-1] == s2[m-1])
            return dp[n][m] = 1 + solve(dp, s1, s2, n-1, m-1);
        else
            return dp[n][m] = max(solve(dp, s1, s2, n-1, m), solve(dp, s1, s2, n, m-1));
    }
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        for(int i=0;i<n+1;i++)
            dp[i][0]=0;
        for(int j=0;j<m+1;j++)
            dp[0][j]=0;

        return solve(dp, s1, s2, n, m);
    }
};