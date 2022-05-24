#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size() == 0) return true;
        queue<int> q;
        unordered_map<int,int> m;
        q.push(source);
        m.insert({source,1});
        
        while(!q.empty()) {
            for(auto& e:edges) {
                if(e[0] == q.front()) {
                    if(e[1] == destination) return true;
                    if(m.find(e[1]) == m.end()) {
                        q.push(e[1]);
                        m.insert({e[1],1});
                    }
                } else {}
                if(e[1] == q.front()) {
                    if(e[0] == destination) return true;
                    if(m.find(e[0]) == m.end()) {
                        q.push(e[0]);
                        m.insert({e[0],1});
                    }
                }
            }
            q.pop();
        }
        return false;
    }
};