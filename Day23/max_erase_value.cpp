#include<bits/stdc++.h>
using namespace std;
//my solution
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int sum=0, subsum=0;
        int maxres=INT_MIN;
        int n=nums.size();
        for(auto i:nums) sum+=i;
        
        unordered_map<int,int> m;
        int i=0,j=1;
        m.insert({nums[i], i});
        subsum+=nums[i];
        while(j<n) {
            if(m.find(nums[j]) == m.end()) {    //no duplicate at j
                m.insert({nums[j], j});
                subsum+=nums[j++];
            }
            else {    //duplicate at j
                maxres=max(maxres, subsum);
                int r=m[nums[j]];
                while(i<=r){   //while i<= first occurence of dupe element
                    subsum-=nums[i];    //update subsum
                    m.erase(nums[i]);   //delete key entry of nums[i] as its no longer in subarray
                    i++;
                }
                subsum+=nums[j];    //add dupe element as its no longer a dupe (as its first occurence is eliminated)
                m.insert({nums[j], j++});   //add to hashmap
            }
        }
        return max(maxres, subsum);
    }
};
//concise discuss section solution
class Solution2 {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int curr_sum = 0, max_sum = 0, l = 0;
        for (int num : nums) {
            while (seen.find(num) != seen.end()) {
                curr_sum -= nums[l];
                seen.erase(nums[l]);
                l += 1;
            }
            curr_sum += num;
            seen.insert(num);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};