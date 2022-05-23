#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0) {
            if(n == 1) return 1;
            else return -1;
        }
        
        int j_guess=-1;//who trusts no one
        unordered_map<int,vector<int>> m;//map for trustor->{trustee1, t2, etc}
        vector<int> v;
        for(auto& i: trust) {
            //for x -> y, add x first + add y to x's trustee list
            if(m.find(i[0]) == m.end())
                m.insert({ i[0],{i[1]} });
            else 
                m[i[0]].emplace_back(i[1]);
            
            //next, add y but dont modify its trustee list
            if(m.find(i[1]) == m.end())
                m.insert({ i[1],v });
            else continue;
        }
        
        for(auto& p: m) {
            if(p.second.size() == 0)
                j_guess=p.first;
        }
        int count=0;
        cout<<j_guess<<endl;
        for(auto& i:trust)
            if(i[1] == j_guess) count++;
        cout<<count<<endl;
        if(count >= n-1) return j_guess;
        //check if everyone trusts j_guess
        return -1;
    }
};