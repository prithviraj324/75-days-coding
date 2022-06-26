#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& pts, int k) {
        int n=pts.size();
        int ans=accumulate(pts.begin() + n-k, pts.end(), 0); //sum of last k elements
        int s=ans;
        int j=n-k;
        for(int i=0;i<k;i++) {  //check for each left element added
            s -= pts[n-k+i];
            s += pts[i];
            ans = max(ans, s);
        }
        return ans;
    }
};