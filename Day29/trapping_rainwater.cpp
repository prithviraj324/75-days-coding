#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int amt=0;
        vector<int> lmax(n,0), rmax(n,0);
        lmax[0]=height[0];
        *rmax.rbegin()=height[n-1];
        
        for(int i=1;i<n;i++) //calculate max height on left and right of each index in the grid
            lmax[i]=max(lmax[i-1], height[i]);
        for(int j=n-2;j>=0;j--)
            rmax[j]=max(rmax[j+1], height[j]);
        
        //amt of water stored at index i->
        //  min(lmax[i], rmax[i]) - h[i], if this is +ve, add it to amt
        // has to be positive bcz if either lmax[i] or rmax[i] is < h[i], then no water will be stored at index i
        
        for(int i=0;i<n;i++)
            if(min(lmax[i], rmax[i]) - height[i] > 0)
                amt+=min(lmax[i], rmax[i]) - height[i];

        return amt;
    }
};