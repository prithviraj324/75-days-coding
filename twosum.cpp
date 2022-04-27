#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> soln={-1,-1};
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) {
            int comp=target-nums[i];
            if(m.find(comp)==m.end()) 
                m.insert({nums[i],i});        
            else if(m.find(comp)!=m.end()) {
                soln[0]=m[comp];
                soln[1]=i;
                
            }
        }
        return soln;
    }
};