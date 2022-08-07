#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool dfs(int course, unordered_map<int, unordered_set<int>>& dep, unordered_set<int>& bt) {
        bool x=true;
        if(dep[course].size() == 0) 
            return true;
        for(auto &pc: dep[course]) {  //pc = prerequisite course
            //int pc = *it;
            if(bt.find(pc) != bt.end()) 
                return false;
            //if(bt.find(-pc) != bt.end()) return true;
            bt.insert(pc);
            x = x && dfs(pc, dep, bt);
            bt.erase(pc);
            
            if(x)   //if course 'pc' could be completed, remove all its prereqs so we dont compute again
                dep[pc] = {};
        }
        return x;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        if(prereq.size() == 0) return true;
        unordered_set<int> bt;
        unordered_map<int, unordered_set<int>> dep;
        for(auto v: prereq) {
            dep[v[0]].insert(v[1]);
            if(dep.find(v[1]) == dep.end())
                dep[v[1]].insert({});
        }
        bool ans=true;
        
        //bt[x] = 0, not visited in dfs path, ie no prereq loop formed
        //bt[x] = 1, already visited, use to check if loop is formed
        
        for(int i=0;i<prereq.size();i++) {
            if(bt.find(-prereq[i][0]) != bt.end())
                continue;
            bt.insert(prereq[i][0]);
            ans = ans && dfs(prereq[i][0], dep, bt);
            bt.erase(prereq[i][0]);
            if(ans)
                bt.insert(-prereq[i][0]);
        }
        return ans;
    }
};

//Kahn's Algo, topo sort
class Solution2 {
public:
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);
        for (auto &p: pre) {
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (degree[i] == 0) q.push(i);
        while (!q.empty()) {
            int curr = q.front(); q.pop(); n--;
            for (auto next: adj[curr])
                if (--degree[next] == 0) q.push(next);
        }
        return n == 0;
    }
};