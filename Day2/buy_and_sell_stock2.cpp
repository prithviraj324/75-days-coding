// -_-
//valley and peak approach
//TECH DOSE video for better understanding
//insanely good solution
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0;
        int valley=0,peak=0;
        for(int i=1;i<prices.size();i++) {
            if(prices[i]>prices[i-1]) 
                p+=prices[i]-prices[i-1];
            else if(prices[i]<prices[i-1])
                continue;
        }
        return p;
    }
};