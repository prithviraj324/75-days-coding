//so easy, it doesnt count
#include<bits/stdc++.h>
using namespace std;
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minh;
    int kx;
    KthLargest(int k, vector<int>& nums) {
        kx=k;
        for(auto i:nums) {
            minh.push(i);
            if(minh.size()>k)
                minh.pop();
        }
    }
    
    int add(int val) {
        minh.push(val);
        if(minh.size()>kx)
                minh.pop();
        
        return minh.top();
    }
};