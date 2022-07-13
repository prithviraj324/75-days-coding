#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //diff type of qn where you optimise for a factor in the 
    int minEatingSpeed(vector<int>& p, int h) {
        int ans=0, n = p.size();
        //wkt h>n otherwise we cant eat 'n' piles in 'h' steps
        //also, worst case, we eat max(piles[]) bananas per hr if h==n, otherwise cant finish pile with max bananas
        //k range -> [1...max[p]]
        //brute force-> for all k in [1....max[p]], check if it can be eated in h hours
        //basically: for(i in k)
        //              for(j=0 to n) {
        //                  if(hours>=h) break;
        //                  hours += ceil(p[j]/i);
        //TC: O(max(p[])*n)
        //using bsearch in keyspace k[1...max(p[])], we can change TC to O(log(max(p[]))*n)
        
        
        int mx=*max_element(p.begin(), p.end());
        int l=1, r=min(mx, 1000000000), k;
        ans = mx;
        //using 'k' as bsearch element, each k is a possible eating speed of koko
        while(l<=r) {
            k = (l+r)/2;
            double hrs=0;
            for(int i=0;i<n;i++) {
                hrs += (p[i]+k-1)/k;
            }   //checked no of hrs taken to eat at speed 'k'
            
            if(hrs <= h) {  //finished eating all in exact time or under, might be possible to eat it faster
                ans = min(k, ans);
                r=k-1;
            }
            else    //took too much time, must eat faster than this, move search space to upper half
                l=k+1;
        }
        
        return ans;
    }
};