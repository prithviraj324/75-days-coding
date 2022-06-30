#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        sort(nums.begin(), nums.end());
        int median = nums[n/2]; // median element as mean is biased towards the side that has duplicates
        //works out for n=odd as there are 2 elements near n/2 that are valid and both give equal diff
        for(int i=0; i<n; i++){
            steps += abs(nums[i] - median); //Adding absolute difference
        }
        return steps;
    }
};