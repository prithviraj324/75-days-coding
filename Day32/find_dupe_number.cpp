#include<bits/stdc++.h>
using namespace std;
//completely unintuitive usage of floyd's cycle detection algo 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Each index is taken 1 based, as if it is zero based, then
        // for nums[2] = 3, if we goto nums[nums[2] - 1], it is again nums[2]
        // infinite loop
        int hare = nums[0], tortoise = nums[0];
        
        do {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        } while(hare != tortoise);
        
        // to find the starting of cycle, make tortoise to start from begining
        tortoise = nums[0];
        while(hare != tortoise) {
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        
        return hare;
    }
};

//smart bit manipulation move to find the duplicate number
//TC: O(32*n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1, res = 0;
        for (int p = 0; p < 32; ++ p) {
            int bit = (1 << p), a = 0, b = 0;
            for (int i = 0; i <= n; ++ i) {
                if (i > 0 && (i & bit) > 0) ++a;
                if ((nums[i] & bit) > 0) ++b;
            }
            if (b > a) res += bit;
        }
        return res;
    }
};