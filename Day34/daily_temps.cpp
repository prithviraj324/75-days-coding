//REVISE MONOTONIC STACK 
#include<bits/stdc++.h>
using namespace std;
//OPTIMISED SOLUTION USING STACK, BRUTE FORCE WOULD BE N^2 CHECK FOR EACH ELEMENT
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> ans(n,0);
        stack<pair<int, int>> st; //st.top (temp[i], i)
        
        st.push({temp[0],0});
        for(int i=1;i<n;i++) {    
            if(st.empty()) {    //if stack is empty, just push value in
                st.push({temp[i], i});
                continue;
            }
            
            if(temp[i] <= st.top().first) { //if next day is colder
                st.push({temp[i], i});
                continue;
            }
            
            else if(temp[i] > st.top().first) { //if next day is warmer, cascade down the stack
                while(!st.empty() && temp[i] > st.top().first) {
                    ans[st.top().second] = i - st.top().second;
                    st.pop();
                }
                st.push({temp[i], i});
            }
        }
        //st.clear();
        return ans;
    }
};
//slightly better solution that stores only index of element onto stack, actually dumb to store pair of temp[i],i
class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> ans(T.size());
        for(int cur = 0; cur < T.size(); cur++) {
            while(T.size() and T[cur] > T[s.top()]) {    // pop till current temp < stack's top's temp. This maintains monotonic stack
                ans[s.top()] = cur - s.top();           // cur day will be next warmer day for each element that's popped
                s.pop();
            }
            s.push(cur);                                // push onto stack to find next warmer day for cur later on
        }
        return ans;
    }
};
//a better solution exists with TC:O(n) and SC:O(1), but is pretty tricky
