#include<bits/stdc++.h>
using namespace std;
//solution is correct, but LC OJ gives TLE
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        //initialization
        for(int i=0;i<m+1;i++)
            dp[i][0]=i;
        for(int i=0;i<n+1;i++)
            dp[0][i]=i;
        
        for(int i=1; i<m+1; i++) {
            for(int j=1; j<n+1; j++) {
                
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                
            }
        }
        int i=m+1, j=n+1;
        string ans="";
        while(i>0 && j>0) {
            if(str1[i-1] == str2[j-1]) {
                ans = str1[i-1] + ans;
                i--;
                j--;
            }
            else if(dp[i-1][j] <= dp[i][j-1]) {
                ans = str1[i-1] + ans;
                i--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans = str2[j-1] + ans;
                j--;
            }
        }
        while(i>0) {
            ans = str1[i-1] + ans;
            i--;
        }
        while(j>0) {
            ans = str2[j-1] + ans;
            j--;
        }
        ans.pop_back();
        return ans;
    }
};