#include<bits/stdc++.h>
using namespace std;
//brute force exponential solution
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
	return min(solve(cost, 0), solve(cost, 1));
}
    int solve(vector<int>& cost, int i) {
        if(i >= cost.size()) return 0; // reached end - no more cost required
        // pay current cost and choose min(step+1, step+2) based on which takes us to end with   minimum cost
        return cost[i] + min(solve(cost, i + 1), solve(cost, i + 2));
    }
};
//memoized top down approach
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
	vector<int> dp(cost.size()); // dp[i] = cost to reach end from ith step 
	return min(solve(cost, dp, 0), solve(cost, dp, 1));
    }
    int solve(vector<int>& cost, vector<int>& dp, int i) {
        if(i >= cost.size()) return 0;
        if(dp[i]) return dp[i];  // if already calculated, directly return stored minimum cost
        return dp[i] = cost[i] + min(solve(cost, dp, i + 1), solve(cost, dp, i + 2)); // same as above, just store in dp[i] before returning
    }
};
//memoized bottom up solution
class Solution3 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n + 1);
        dp[0] = cost[0], dp[1] = cost[1];
        for(int i = 2; i <= n; i++) 
            dp[i] = (i != n ? cost[i] : 0) + min(dp[i - 1], dp[i - 2]);  // we can reach here from i-1th or i-2th step - choose minimum
        return dp[n];
    }
};

//simpler approach using dp but no recursion concept
class Solution4 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int minCost[n+1];
        
        minCost[0] = minCost[1] = 0;
        
        for(int i=2; i<n+1;i++) {
            minCost[i] = min(cost[i-1] + minCost[i-1], cost[i-2] + minCost[i-2]);
        }
        
        return minCost[n];
    }
};