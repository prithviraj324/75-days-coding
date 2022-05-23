#include<bits/stdc++.h>
using namespace std;


/*----------------------------------------------------------------
brute force first Solution
j_guess is judge guess, map each person to whoever he trusts
        1->2 1 trusts {2,3,4,5}
          \3
          \4
          \5
now loop thru map to check if there exists someone who trusts no one, this is j_guess, else return 0
now see if everyone trusts town judge guessed above
    i.e see if j_guess occurs in pair[1] atleast n-1 times 
TC-O(n) and SC-O(n2)
*/
//----------------------------------------------------------------
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
//-------------------------------
// better solution 
/*redundancy in storing which node trusts who all
rather store each node trust how many nodes & how many nodes trust this node
TC-O(n), SC-O(n)
*/
class Solution2 {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //this condition is to check if given input is empty but n==1
		
		if(trust.empty() && n==1)
            return 1;
		
		//counts outdegree of a person or node 
		//outdegree means number of nodes that are trusted by given specific node 
        
		vector<int> out(n+1,0);
		
		//counts indegree of a person or node 
		//indegree means number of nodes that trusts a given specific node
        
		vector<int> in(n+1,0);
		
		//loop counts indegree and outdegree
        
		for(auto edge : trust){
            out[edge[0]]++;
            in[edge[1]]++;
        }
		
		//if a node has outdegree==0 that means that node doesnot trust anyone and
		//indegree ==n-1 that means all other nodes trusts this node except himself
        
		for(int i=0;i<=n;i++){
            if(out[i]==0 && in[i]==n-1)
                return i;
        }
		//if there is no such node return -1
        return -1;
    }
};