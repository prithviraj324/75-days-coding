#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:
    queue<int> q1,q2;
    MyStack( ) { }
    
    void push(int x) {
        q1.push(x);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int x=q2.front();
        q2.pop();
        return x;
    }
    
    int top() {
        return q2.front();
    }
    
    bool empty() {
        return q2.empty();
    }
};