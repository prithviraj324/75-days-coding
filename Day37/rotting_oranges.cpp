#include<bits/stdc++.h>
using namespace std;

//own approach same as actual solution, cannot find erroe hence commented out
// class Solution {
//     //DFS wont work as multiple rotten oranges will rot their neighbours simultaneously
    
// public:
//     int dx[4] = {0, 0, 1, -1};
//     int dy[4] = {1, -1, 0, 0};
//     int orangesRotting(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         queue<pair<int, int>> q;
//         int time=0;
//         int f=0;
//         for(int i=0;i<m;i++) {
//             for(int j=0;j<n;j++)  {
//                 if(grid[i][j] == 1)
//                     f++;
//                 if(grid[i][j] == 1)
//                     q.push({i,j});
//             }
//         }
        
//         while(!q.empty() && f > 0) {
//             int k=q.size();
//             for(int x=0; x<k ;x++) {   //only expanding rotten oranges in one minute
//                 pair<int, int> p=q.front();
//                 q.pop();
//                 for(int i=0;i<4;i++) {  //all surrounding valid nodes added to q
//                     int nx=p.first + dx[i];
//                     int ny=p.second + dy[i];
//                     if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny] != 1) 
//                         continue;
//                     grid[nx][ny] = 2;
//                     q.push({nx, ny});
//                     f--;    //a fresh ornage rotted
//                 }
//             }   //bfs done on one level, 1 unit of time passes
//             time++;
//         }
        
//         if(f==0) return time;
//         else return -1;
        
//     }
// };

class Solution {
public:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) rotten.push({i, j});
            }
        }
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k; 
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) days++;
        }
        
        return tot == cnt ? days : -1;
    }
};