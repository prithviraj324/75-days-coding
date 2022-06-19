#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestCommonSubstr(string s1, string s2, int n, int m)
    {
        // your code here
        int res=-1;
        if(n==0 || m==0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        for(int i=0;i<n+1;i++)
            dp[i][0]=0;
        for(int j=0;j<m+1;j++)
            dp[0][j]=0;
        
        for(int i=1;i<n+1;i++) {
            for(int j=1;j<m+1;j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    res=max(res, dp[i][j]);
                }
                else
                dp[i][j]=0;
            }
        }
        if(res==-1) return 0;
        return res;
    }
};