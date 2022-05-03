#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s) {//using normal for loop increases time taken by
            if(c=='(' || c=='{' || c=='[')
                st.push(c);
            else if(!st.empty()){
                if(c==')' && st.top()=='(')
                    st.pop();
                else if(c=='}' && st.top()=='{')
                    st.pop();
                else if(c==']' && st.top()=='[')
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};