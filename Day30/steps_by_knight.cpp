#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    pair<int,int> arr[8]={{2,1},{1,2},{-2,-1},{-1,-2},{-1,2},{-2,1},{2,-1},{1,-2}};
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int vis[N+1][N+1]={0};
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0],KnightPos[1]});
	    vis[KnightPos[0]][KnightPos[1]]=1;
	    int step=0;
	    while(!q.empty()){
	        int sz=q.size();
	        while(sz--){
	            auto x=q.front();
	            q.pop();
	            int a=x.first;
	            int b=x.second;
	            if(a==TargetPos[0] and b==TargetPos[1]) return step;
	            for(int i =0;i<8;i++)   {
	                int j=a+arr[i].first;
	                int k=b+arr[i].second;
	                if(j>0 and k>0 and j<=N and k<=N and !vis[j][k]) {
	                    q.push({j,k});
	                    vis[j][k]=1;
	                }//if
	            }//for
	        }//inner while
	        step++;
	    }//while loop
	   return -1; 
	}
};