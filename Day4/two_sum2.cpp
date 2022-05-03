#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        vector<int> v(2,0);
        while(l<r) {
            if(numbers[l]+numbers[r] < target)
                l++;
            else if(numbers[l]+numbers[r] > target) 
                r--;
            else {
                v[0]=l+1;
                v[1]=r+1;
                break;
            }
        }
        return v;
    }
};