#include<bits/stdc++.h>
using namespace std;
//NOTE****: make sure there is a way to tell visisted nodes apart form unvisited nodes, here it is done using the fact that unviisted nodes are either -1 or INT_MAX
class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here
        int m=rooms.size();
        int n=rooms[0].size();

        queue<vector<int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(rooms[i][j] == 0)
                    q.push({i,j});  //push all gates to queue
            }
        }

        while(!q.empty()) {
            int k =q.size();
            cout<<k<<",";
            for(int x=0;x<k;x++) {  //expand all node on frontier
                vector<int> pt = q.front();
                q.pop();
                for(int i=0;i<4;i++) {  //expanding node
                    int nx=pt[0] + dx[i];
                    int ny=pt[1] + dy[i];
                    if(nx<0 || ny<0 || nx>=m || ny>=n) continue;    //outofbounds
                    if(rooms[pt[0]][pt[1]] == -1) continue;  //wall encountered, ignore
                    if(rooms[nx][ny] == INT_MAX) {
                        rooms[nx][ny] = rooms[pt[0]][pt[1]] + 1;    //valid gate
                        q.push({nx, ny});
                    }
                }
            }   //expanded all frontier nodes
        }// done till queue empty
    }
};