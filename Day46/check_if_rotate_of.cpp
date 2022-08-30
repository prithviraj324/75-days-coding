#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool res[4] = {true, true, true, true};
        int n=mat.size();
        for(int i=0;i<n && res;i++) {
            for(int j=0;j<n && res; j++) {
                if(mat[i][j] != target[j][n-i-1])   //90deg rot
                    res[0] = false;
                if(mat[i][j] != target[n-i-1][n-j-1])   //180 deg rot
                    res[1] = false;
                if(mat[i][j] != target[n-j-1][i])   //270deg rot
                    res[2] = false;
                if(mat[i][j] != target[i][j])   //same
                    res[3] = false;
            }
        }
        
        return res[0] || res[1] || res[2] || res[3];
    }
};