#include<bits/stdc++.h>
using namespace std;
//can be done using dp also, but this is O(n) solution
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), len = 1, prevDiff = 0, currDiff;
        for(int i = 1; i < n; i++){
            currDiff = nums[i] - nums[i - 1];
            //below if stmt takes care of all possible cases, try and think through the logic
            //if prevdiff was -ve and curdiff is +ve, include i in subseq, OR
            //if prevdiff was +ve and curdiff is -ve, include i in subseq
            if((currDiff > 0 && prevDiff <= 0) || (currDiff < 0 && prevDiff >= 0))
                len++, prevDiff = currDiff; //set prevdiff = curdiff for next iteration
        }
        return len;
    }
};