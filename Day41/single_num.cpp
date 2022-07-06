#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp=0;
        for(int n:nums) 
            temp= temp ^ n;
        
        return temp;
    }
};