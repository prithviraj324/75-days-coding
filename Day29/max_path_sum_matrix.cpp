#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& mat, int i, int j) {
        if(i<0 || j<0 || i>=mat.size() || j>=mat.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = mat[i][j] + max(max(solve(dp, mat, i+1, j), solve(dp, mat, i+1, j-1)), solve(dp, mat, i+1, j+1));
    }
    int maximumPath(int N, vector<vector<int>> mat)
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int maxi=-1;
        for(int i=0;i<N;i++)
            maxi = max(maxi, solve(dp, mat, 0, i));
        return maxi;
    }
};