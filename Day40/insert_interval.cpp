#include<bits/stdc++.h>
using namespace std;
//pretty useless qn, just to test thinking of edge cases
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intvs, vector<int>& newint) {
        vector<vector<int>> ans;
        if(intvs.size()==0) {
            ans.push_back(newint);
            return ans;
        }
        bool inserted=false;
        //cout<<intvs.size();
        for(int i=0;i<intvs.size();i++) {
           // cout<<inserted<<",";
            if(inserted) {
                ans.push_back(intvs[i]);
                continue;
            }

            if(intvs[i][0] <= newint[0]) {  
                if(intvs[i][1] < newint[0])  {//in a lower interval
                    ans.push_back(intvs[i]);
                    continue;
                }
                
                if(newint[0] <= intvs[i][1]) { //new intv starts in old intv
                    if(newint[1] <= intvs[i][1]) {   //new interval is inside old interval
                        ans.push_back(intvs[i]);
                        inserted=true;
                        continue;
                    }
                    int left=intvs[i][0], right=intvs[i][1];
                    while(i<intvs.size() && intvs[i][0] <= newint[1]) {
                        right = max(intvs[i][1], newint[1]);
                        //cout<<i<<endl;
                        i++;
                    }
                    ans.push_back({left, right});
                    i--;
                    inserted=true;
                    continue;
                }
            }
            
            else if(newint[0] < intvs[i][0]) {
                if(newint[1] < intvs[i][0]) {
                    ans.push_back({newint[0], newint[1]});
                    i--;
                    inserted=true;
                    continue;
                }
                int left=newint[0], right = newint[1];
                while(i<intvs.size() && intvs[i][0] <= newint[1]) {
                    right=max(intvs[i][1], newint[1]);
                    i++;
                }
                ans.push_back({left, right});
                i--;
                inserted=true;
                continue;
            }
        }
        if(!inserted)
            ans.push_back(newint);
        
        return ans;
    }
};