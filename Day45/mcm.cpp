#include<bits/stdc++.h>
using namespace std;

//recursive brute force solution, gives TLE
class Solution{
public:
    int solve(int arr[], int n, int i, int j) {
        if(i>=j) return 0;
        if(j-i == 1) return arr[i-1]*arr[i]*arr[i+1];
        int ans=INT_MAX;
        for(int k=i;k<j;k++) {
            ans = min(ans, 
                    solve(arr, n, i, k) + solve(arr, n, k+1, j) + arr[i-1]*arr[k]*arr[j]
                  );
        }
        return ans;
    }
    int matrixMultiplication(int N, int arr[]) {
        // code here
        return solve(arr, N, 1, N-1);
    }
};

//top down with memoization
class Solution2{
public:
    int solve(vector<vector<int>>& dp, int arr[], int n, int i, int j) {
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(j-i == 1) return arr[i-1]*arr[i]*arr[i+1];
        int ans=INT_MAX;
        for(int k=i;k<j;k++) {
            ans = min(ans, 
                    solve(dp, arr, n, i, k) + solve(dp, arr, n, k+1, j) + arr[i-1]*arr[k]*arr[j]
                  );
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[]) {
        // code here
        vector<vector<int>> dp(N, vector<int>(N,-1));
        
        return solve(dp, arr, N, 1, N-1);
    }
};