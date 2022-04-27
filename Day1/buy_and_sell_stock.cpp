#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,pmax=*(prices.rbegin()),pnew=-1;
        for(auto i=prices.rbegin()+1; i!=prices.rend(); i++) {
            pnew=pmax-(*i);
            if(pnew>=profit)
                profit=pnew;
            if(pmax<*i)
                pmax=*i;
        }
        return profit;
    }
};