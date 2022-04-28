/*

--SUB-OPTIMAL SOLN: TC-N,SC-N

int majorityElement(vector<int>& nums) {
        int min=nums.size()/2;
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++) {
            if(m.find(nums[i])==m.end())
                m.insert({nums[i],1});
            else {
                m[nums[i]]+=1;
            }
        }
        
        for(auto i:m) {
            if(i.second>min)
                return i.first;
        }
        return -1;
    }
*/

//MOORE'S VOTING ALGORITHM: TC-N,SC-O(1)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int min=nums.size()/2;
        int cand=nums[0],count=1;
        for(int i=1;i<nums.size();i++) {
            if(cand==nums[i])
                count++;
            else
                count--;
            if(count<0) {
                cand=nums[i];
                count=1;
            }
        }
        return cand;
    }
};