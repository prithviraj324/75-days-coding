#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<string>& s, stack<char> st, string x, int n) {
        if(n==0) {
            while(!st.empty()) {
                x.push_back(')');
                st.pop();
            }
            s.push_back(x);
            return;
        }
        else {
            st.push('(');
            dfs(s, st, x+"(", n-1);
            
            st.pop();
            if(!st.empty() && st.top() == '(') {
                st.pop();
                x.push_back(')');
                dfs(s, st, x, n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        stack<char> st;
        string temp;
        dfs(ans, st, temp, n);
        return ans;
    }
};

//better and faster, memory efficient way, directly from discuss section 
class Solution2 {
public:
    vector<string> ans;
    void f(string s,int open,int close){        //open => '(' count remaining
        if(open==0&&close==0){                  //close=> ')' count remaining
            ans.push_back(s);
            return;
        }
        if(open>0)f(s+"(",open-1,close);
        if(open<close)f(s+")",open,close-1);    //'(' must be placed before ')'
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        f("",n,n);                              //Balanced string will have
        return ans;                             //n-open and n-closing brackets
    }
};