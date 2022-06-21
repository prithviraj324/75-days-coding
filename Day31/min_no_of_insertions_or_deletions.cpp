#include<bits/stdc++.h>
using namespace std;

class Solution{
		
	public:
	int solve(vector<vector<int>>& dp, string& x, string& y, int m, int n) {
	    if(dp[m][n] != -1) return dp[m][n];
	    if(x[m-1] == y[n-1])
	        return dp[m][n] = 1 + solve(dp, x, y, m-1, n-1);
	    else
	        return dp[m][n] = max(solve(dp, x, y, m-1, n), solve(dp, x, y, m, n-1));
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m=str1.size();
	    int n=str2.size();
	    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
	    dp[0]=vector<int>(n+1, 0);
	    for(int i=0;i<m+1;i++) 
	        dp[i][0]=0;
	        
	    int lcs=solve(dp, str1, str2, m, n);
	    return m+n-2*lcs;
	} 
};