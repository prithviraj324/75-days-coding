#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, -1);
        if(n==0) return {0};
        if(n==1) return {0,1};
        ans[0]=0;
        ans[1]=1;
        for(int i=2;i<n+1;i++) {
            int count=0, num=i;
            while(num>1 && ans[num] == -1) {
                count += num%2;
                num/=2;
            }
            ans[i] = count + ans[num];
        }
        
        return ans;
    }
};