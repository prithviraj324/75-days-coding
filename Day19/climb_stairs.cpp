#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int steps(int n, vector<int>& v) {
        if(v[n] != -1) return v[n];
        if(n<=1)  return 1;
        else if(n==2)
            return steps(n-1, v) + steps(n-2, v);
        else {
            v[n-1] = steps(n-1, v);
            v[n-2] = steps(n-2, v);
            return v[n-1]+v[n-2];
        }
    }
    int climbStairs(int n) {
        vector<int> v(n+1,-1);
        return steps(n,v);
    }
};