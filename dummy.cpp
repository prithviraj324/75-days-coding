#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fun() { 
        vector<int> v={2,3,4,5,6};
        v.insert(v.begin(),1);
        for(auto i:v) 
            cout <<i<<endl;
        return 0;
    }
};
int main() {
    Solution s;
    s.fun();
    return 0;
}