#include<bits/stdc++.h>
using namespace std;
//brute force exponential, sometimes doesnt work
class Solution {
  public:
  int size=0;
    long long int solve(int coins[], int amt, int val) {//S[]= coins[], amt= amt to be achieved, val=coin denomination used, given by coins[val]
        if(amt==0) return 1;
        if(val>=size || amt < 0) return 0;
        if(coins[val] <= amt)
            return solve(coins, amt-coins[val], val) + solve(coins, amt, val+1);
        else
            return solve(coins, amt, val+1);
    }
    long long int count(int S[], int m, int target) {
        //m types of coins, must add up to value target
        //s.size = m
        size=m;
        return solve(S, target, 0);
    }
};
//top down memoized
class Solution2 {
  public:
    long long int count(int S[], int m, int n) {

        // code here.
        
        long long dp[m+1][n+1];
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
            }
        }
        
        for(int i=1;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(S[i-1]<=j)
                    dp[i][j]= dp[i][j-S[i-1]] + dp[i-1][j];
                else
                    dp[i][j]= dp[i-1][j];
            }
        }
        
        return dp[m][n];
    }
};