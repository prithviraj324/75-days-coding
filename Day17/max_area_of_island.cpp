#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i, int j, int r, int c, vector<vector<int>>& grid, int& area) {
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]==0) return;
        
        area++;
        grid[i][j]=0;
        dfs(i+1, j, r, c, grid, area);
        dfs(i-1, j, r, c, grid, area);
        dfs(i, j+1, r, c, grid, area);
        dfs(i, j-1, r, c, grid, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0, area=0;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {//if unvisited
                    dfs(i,j,grid.size(), grid[0].size(), grid, area);//perform dfs on island
                    maxArea=max(maxArea,area);//compare with max area seen thus far
                    area=0;//reset area for next island
                }//if
            }//for
        }//for
        
        return maxArea;
    }
};