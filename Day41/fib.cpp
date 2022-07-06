#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& dp, int n) {
        if(dp[n-1] > -1) 
            return dp[n-1];
        else 
            return dp[n-1] = solve(dp, n-1) + solve(dp, n-2);
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        if(n < 2) return n;
        dp[0] = 0;
        dp[1] = 1;
        
        //for(int n:dp) cout<<n<<", ";
        return solve(dp, n+1);
    }
};