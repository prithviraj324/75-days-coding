#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	int minDifference(int arr[], int n)  { 
	    /*
	    ->S1 + S2 = maxsum
	    ->ie S2=maxsum-S1
	    ->to find: |S2-S1|which is = maxsum-2S1 by locking S1 to be <= maxsum/2
	    ->in subset sum problem, last row of dp table tell us whether we can get a subset of sum 'j' using all n
	      elements in the array
	    ->using this, we can find from j=maxsum/2 -> 0 whether any of dp[n][j] is true or false
	    ->the first one which is true, we subtract 2*that from maxsum to get min diff of subsets ans  
	    */
	    int sum=0;
	    for(int i=0;i<n;i++)
	        sum+=arr[i];
	    bool dp[n+1][sum+1];
	    for(int i =0;i<n+1;i++)
	        dp[i][0]=true;
	    for(int j=1;j<sum+1;j++)
	        dp[0][j]=false;
	    for(int i =1;i<n+1;i++){
	        for(int j =1;j<sum+1;j++){
	            if(arr[i-1]<=j){
	                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
	                
	            }else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    int j=sum/2;
	    while(j>=0){
	        if(dp[n][j])
	            return sum-(2*j);
	        j--;
	    }
	} 
};