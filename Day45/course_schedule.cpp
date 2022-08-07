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