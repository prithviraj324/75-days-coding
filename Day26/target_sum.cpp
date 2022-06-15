#include<bits/stdc++.h>
using namespace std;
//brute force soln, oddly didnt tle
class Solution {
public:
    int solve(vector<int>& nums, int target, int sum, int i) {
        if(i<0 && sum==target) return 1;
        else if(i<0) return 0;
        //either add of subtract to/from current sum
        return solve(nums, target, sum + nums[i], i-1) + solve(nums, target, sum - nums[i], i-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, nums.size()-1);
    }
};
//top down memoized solution
class Solution {
public:
    //This question is same as number of subsets with given difference 
    //Given sum = target
    //difference between 2 subsets, subset1->S1-> has all elements that u add +
    //                              subset2->S2-> has all elements that u subtract -
    // wkt Sum(s1) - Sum(s2) = target
    //     Sum(s1) + Sum(s2) = Sum(nums)==sum
    // hence, 2S1=target+sum or s1=(target + sum)/2
    //find number of subsets that add up to S1
    int countSubsets(vector<int>& nums, int n, int M)
    {
        int t[n+1][M+1];
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=M; j++) {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }

        for(int i=1; i<=n; i++) {
            for(int j=0; j<=M; j++) {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }

        return t[n][M];  
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
         target=abs(target);
         int n=nums.size();
         int sum=0;

         for(int i=0; i<n; i++)
             sum+=nums[i];

        int M=(sum+target)/2;
        if(sum<target||(sum+target)%2!=0)
            return 0;
        
         return countSubsets(nums, n, M);
    } 
};