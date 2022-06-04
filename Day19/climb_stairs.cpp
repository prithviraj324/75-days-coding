#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //memoized bottom up solution
    int steps(int n, vector<int>& v) {
        if(v[n] != -1) return v[n];//check if already memoized
        if(n<=1)  return 1;//base condition
        else {//recursive calls
            v[n-1] = steps(n-1, v);//choice: take 1 step
            v[n-2] = steps(n-2, v);//choice: take 2 steps
            return v[n-1]+v[n-2];
        }
    }
    int climbStairs(int n) {
        vector<int> v(n+1,-1);
        return steps(n,v);
    }
};