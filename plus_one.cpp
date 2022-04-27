#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cover=1;
        for(auto i=digits.rbegin(); i!=digits.rend() && cover!=0; i++) {
            if(*i==9 && i==digits.rend()-1) {
                *i=0;
                digits.push_back(1);
                rotate(digits.rbegin(),digits.rbegin()+1,digits.rend());
                break;
            }
            else if(*i==9) {
                *i=0;
                cover=1;
            }
            else {
                *i=*i + cover;
                cover=0;
            }
        }
        return digits;
    }
};