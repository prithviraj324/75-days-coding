#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int r=grid.size(), c=grid[0].size();
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == '1') {
                    dfs(r, c, i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
    
protected:
    void dfs(int r, int c, int i, int j, vector<vector<char>>& grid) {
        if(i < 0 || j < 0 || i >=r || j >=c || grid[i][j]  == '0') return;
        
        grid[i][j]='0';
        dfs(r, c, i+1, j, grid);
        dfs(r, c, i-1, j, grid);
        dfs(r, c, i, j+1, grid);
        dfs(r, c, i, j-1, grid);
    }
};