#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            //ans += n % 2;
            //above line using bitmanipulation 
            ans += n&1; //adds 1 if last bit is 1 i.e odd, else adds 0 i.e. even
            n >>= 1;
        }
        
        return ans;
    }
};