#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int maxi=-1;
        for(auto c:n) 
            maxi = max(c-'0', maxi);
        return maxi;
    }
};