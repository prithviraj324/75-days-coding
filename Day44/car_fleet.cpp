#include<bits/stdc++.h>
using namespace std;class Solution {
public:
    struct compare {
        bool operator()(pair<int, int>& p, pair<int, int>& q) {
            return p.first > q.first;
        }
    };
    int carFleet(int target, vector<int>& pos, vector<int>& vel) {
        int n = pos.size();
        //just math, use graph to know why
        //posn and speed of each car is given
        //graph posn wrt time, posn is  y-intercept, speed is slope
        //this gives a line
        //number of fleets = n - number of intersections, bcz two cars become one
        //intersection calculation not needed, as for each pair<pos, speed>, we can calculate time to reach target
        //if car at idx 5 takes 5s to reach target, but a car at idx<5 takes time<5 to reachtarget, that means intersection, so combine them
        //eliminate car at idx<5 and assume car fleet = car at idx 5 with time 5s
        vector<pair<int, int>> p;
        for(int i=0;i<n;i++)
            p.push_back({pos[i], vel[i]});
        
        double temp;
        sort(p.begin(), p.end(), compare());
        stack<double> st;
        for(auto pr: p) {
            st.push((double) (target-pr.first)/pr.second);
            if(st.size()>=2) {
                temp=st.top();
                st.pop();
                if(temp <= st.top())     //prev car reaches before latest car
                    continue;
                else 
                    st.push(temp);
            }
        }
        
        return st.size();
    }
};