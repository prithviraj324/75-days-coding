#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> prev;
        v.push_back({1});
        if(numRows==2) {
            v.push_back({1,1});
            return v;
        }
        else if(numRows!=1)
            v.push_back({1,1});
        
        for(int i=3;i<=numRows;i++) {   
            v.push_back(vector<int>(i,0));      //      1
            v[i-1][0]=1;                        //     1 1
            v[i-1][i-1]=1;                      //     121
            for(int j=1;j<i-1;j++){             //    13 31
                v[i-1][j]=v[i-2][j-1]+v[i-2][j];//
            }
        }
            
        return v;
    }
};