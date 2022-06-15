#include<bits/stdc++.h>
using namespace std;
//brute force exponential solution
class Solution{
  public:
    int cut(int price[], int n, int remlen, int i) {
        if(remlen==0 || i==0) return 0;
        if(i <= remlen) //if choice of cut is <= remaining length of rod, choose either cut length of i or not
            return max(price[i-1] + cut(price, n, remlen-i, i), cut(price, n, remlen, i-1));
        else
            return cut(price, n, remlen, i-1);
    }
    int cutRod(int price[], int n) {
        //code here
        //vector<vector<int>> dp()
        return cut(price, n, n, n);
    }
};
//top down memoized
class Solution2 {
  public:
    int cut(vector<vector<int>>& dp, int price[], int n, int remlen, int i) {
        if(remlen==0 || i==0) return 0; //i=length of section of rod being cut
        if(dp[remlen][i] != -1) return dp[remlen][i];
        
        if(i <= remlen) //if choice of cut is <= remaining length of rod, choose either cut length of i or not
            return dp[remlen][i] = max(price[i-1] + cut(dp, price, n, remlen-i, i), cut(dp, price, n, remlen, i-1));
        else
            return dp[remlen][i] = cut(dp, price, n, remlen, i-1);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i=0;i<n+1;i++) {
            dp[i][0]=0;
            dp[0][i]=0;
        }
        return cut(dp, price, n, n, n);
    }
};
//bottom up memoized
