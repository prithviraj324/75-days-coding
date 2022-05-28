#include<bits/stdc++.h>
using namespace std;
//solution using heap
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> minh;
        for(auto i:nums) {
            minh.push(i);
            if(minh.size() > 2)
                minh.pop();
        }
        int x=minh.top();
        minh.pop();
        return (x-1)*(minh.top()-1);   
    }
};
//another solution, using linear sweep to find largest and 2nd largest elements