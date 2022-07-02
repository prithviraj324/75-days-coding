#include<bits/stdc++.h>
using namespace std;
//own first soln: turns out logic is flawed. 29/52 passed
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereqs) {
        unordered_map<int, vector<int>> m;
        queue<int> q;
        for(auto v:prereqs) {
            m[v[0]].push_back(v[1]);
        }   //created adj list of course dependencies
        for(auto p:m)
            q.push(p.first);    //push all courses whose dependencies must be satisfied
        
        //start bfs on each of the courses. If any course is revisited, we can safely say a loop exists and courses cannot be finished -> ONE EXCEPTION EXPLAINED BELOW
        vector<bool> visited(n, false);
        
        while(!q.empty()) {
            int k = q.size();
            cout<<k<<", \n";
            for(int i=0;i<k;i++) {
                int fr=q.front();
                cout<<fr<<", ";
                q.pop();
                if(m.find(fr) == m.end()) continue; //EXCEPTION: if a course doesnt have dependencies, we can do that course any number of times and still be able to pass all courses
                if(visited[fr]) return false;
                visited[fr] = true;
                for(auto n:m[fr])   //expanding dependency list
                    q.push(n);
            }
            cout<<"end \n";
        }
        
        return true;    //no loop found, course schedule queue exhausted
    }
};

