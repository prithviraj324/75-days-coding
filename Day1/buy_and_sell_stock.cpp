#include<bits/stdc++.h>
using namespace std;
//2 ptrs, one is at end(right ptr) and the other is end-1(left ptr)
//keep decrementing leftptr till u reach beginning of array
//pricemax stores value of max price thus far seen in subarray [l,r]
//at each step, calculate (leftptr - pricemax), ie buy at day leftptr and sell at day pricemax for max profit
//update maxprofit and pricemax accordingly
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0, pricemax=*(prices.rbegin()), pnew=-1;
        for(auto i=prices.rbegin()+1; i!=prices.rend(); i++) {
            pnew = pricemax - (*i);
            if(pnew >= maxprofit)
                maxprofit = pnew;
            if(pricemax < *i)
                pricemax = *i;
        }
        return maxprofit;
    }
};