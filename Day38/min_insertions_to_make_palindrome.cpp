#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:
    int solve(vector<vector<int>>& dp, string& s, int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i-1] == s[j-1] && i == j)
            return dp[i][j] = 1 + solve(dp, s, i-1, j+1);
        else if(s[i-1] == s[j-1] && i != j)
            return dp[i][j] = 2 + solve(dp, s, i-1, j+1);
        else
            return dp[i][j] = max(solve(dp, s, i-1, j), solve(dp, s, i, j+1));
    }
  public:
    int countMin(string str){
        //code here
        int n=str.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        for(int i=0;i<n+2;i++) {
            dp[i][0]=0;
            dp[i][n+1]=0;
            dp[0][i]=0;
            dp[n+1][i]=0;
        }
        int maxi=0; //length of longest palindromix subseq
        for(int i=1;i<n+1;i++) {
            maxi=max(maxi, max(solve(dp, str, i, i), solve(dp, str, i, i+1)));
        }
        return n-maxi;
    }
};