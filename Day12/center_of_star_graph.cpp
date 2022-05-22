#include<bits/stdc++.h>
using namespace std;
//----------------------------------------------------------------
//using map to find number of occurences of each node in edges and printing out node that repeats most times
//tc-O(n), sc-O(n)
//----------------------------------------------------------------
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int max=INT_MIN, nodeval;
        unordered_map<int,int> m;
        
        for(auto i:edges) {//use auto& i here for 2x speed boost, copies are not used
            if(m.find(i[0]) == m.end()) 
                m.insert({i[0],1});
            else
                m[i[0]]++;
            
            if(m.find(i[1]) == m.end()) 
                m.insert({i[1],1});
            else
                m[i[1]]++;
        }
        for(auto p:m) {
            if(p.second > max) {
                max = p.second;
                nodeval=p.first;
            }
        }
        return nodeval;
    }
};
//----------------------------------------------------------------
//using self implemented map using array
//weirdly 2x faster than above
//-------------------------------
class Solution2 {
public:
    int findCenter(vector<vector<int>>& edges) {
        int N = edges.size()+1;
        vector<int> count(N + 1, 0);
        for (auto& t : edges)
            count[t[0]]++, count[t[1]]++;
        for (int i = 1; i <= N; ++i) {
            if (count[i] == N - 1) return i;
        }
        return -1;
    }
};
//-------------------------------
//read up on star graphs, only one node has degree>1
//compare 2 edges and get the common vertex
//this vertex is center of star graph
//tc-O(1)
//-------------------------------
class Solution3 {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};