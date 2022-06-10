#include<bits/stdc++.h>
using namespace std;
//brute force exponential solution
class Solution {
public:
    bool select(vector<int>& nums, int lsum, int rsum, int i) {
        if(i<0) {
            if(lsum != rsum)
                return false;
            else return true;
        }
        else { //either add nums[i] to left subset or right subset
            return select(nums,lsum+nums[i], rsum, i-1) || select(nums,lsum, rsum+nums[i], i-1);
        }
    }
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 1) return false;
        int lsum=0, rsum=0;
        return select(nums, lsum, rsum, nums.size()-1);
    }
};
//----------------------------------------------------------------
//top down iterative subset sum solution copy pasted here, read comments for explaination
//----------------------------------------------------------------
class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        //nums[] is universal set U
        if(nums.size() == 1) return false;
        int max=0;
        for(auto i:nums) max+=i; //compute sum of all elements
        int n=nums.size();
        //wkt we have to find 2 subsets A & B that add up to a common sum S
        // we also know that A U B = U (nums[]) array, hence sum of nums[]=2*S
        //so, equal sum partition is possible only if sum(nums[]) is even
        
        //find 2S by computing sum, then find if there is a subset having sum=S
        //problem decomposes into subset sum question
        //if there is a set A whose sum is S, then U-A = B is the other subset having all other elements that add up to S
        if(max%2 != 0) return false;
        else {
            int sum=max/2;
            vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
            for(int i=0;i<=n;i++) 
                dp[i][0]=true;
            for(int j=0;j<=sum;j++) 
                dp[0][j]=false;
            
            for(int i=1;i<n+1;i++) {
                for(int j=1;j<sum+1;j++) {
                    if(nums[i-1] <= j)   //can take that element towards sum calculation
                        dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j]; //choose or dont choose
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
            return dp[n][sum];
        }
    }
};