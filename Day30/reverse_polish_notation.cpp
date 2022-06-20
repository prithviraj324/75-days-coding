#include<bits/stdc++.h>
using namespace std;
//evaluate postfix notation
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int t1, t2, comp;
        for(auto t:tokens) {
            if(t=="/"  || t=="*" || t=="+" || t=="-") {
                t2=st.top();
                st.pop();
                t1=st.top();
                st.pop();
                if(t=="/")  comp=t1/t2;
                else if(t=="*")    comp=t1*t2;
                else if(t=="+")    comp=t1+t2;
                else if(t=="-")    comp=t1-t2;
                st.push(comp);
            }
            else {
                st.push(stoi(t));
            }
        }
        
        return st.top();
    }
};