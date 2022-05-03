#include<bits/stdc++.h>
using namespace std;
class MinStack {
    //usually not allowed to use std::stack, so implement using vector
    vector<pair<int,int>> v;
    public:
    MinStack() {}
    void push(int val) {
        if(v.size()==0)
            v.push_back({val,val});
        else {
            int min=v.back().second;
            if(val<=min)
                v.push_back({val,val});//inserts lowest value as min
            else
                v.push_back({val,min});//inserts previous minimum value as min
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */