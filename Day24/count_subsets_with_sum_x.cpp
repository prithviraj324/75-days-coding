#include<bits/stdc++.h>
using namespace std;
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        const int k=1e9+7;
        int count=0;
        vector<vector<int>> dp(n+1, vector<int>(sum+1,0));
        // for(int i=0;i<n+1;i++)
        //     dp[i][0]=1;  //set of elements, sum to reach=0, can achieve by choosing no elements
        dp[0][0]=1;
        for(int i=1;i<n+1;i++) {
            for(int j=0;j<sum+1;j++) {
                if(arr[i-1] <= j) 
                    dp[i][j]=(dp[i-1][j-arr[i-1]] + dp[i-1][j])%k;
                else 
                    dp[i][j]+=(dp[i-1][j])%k;
            }
        }
        return dp[n][sum]%k;
	}
	  
};