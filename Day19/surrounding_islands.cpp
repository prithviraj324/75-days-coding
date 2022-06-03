#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i, int j, int r, int c, vector<vector<char>>& board) {
        if(i<0 || j<0 || i==r || j==c || board[i][j]!='O') return;
        
        board[i][j]='T';
        dfs(i+1, j, r, c, board);
        dfs(i-1, j, r, c, board);
        dfs(i, j+1, r, c, board);
        dfs(i, j-1, r, c, board);
    }
    void solve(vector<vector<char>>& board) {
        //WKT any 'O' on the border is unsurrounded by X's on all sides
        if(board.size() == 1 || board[0].size() == 1) return;
        //Phase 1: capture unsurrounded nodes (run dfs on each border node that is O, O -> T )
        //Phase 2: Replace all remaining O's on board with X's as they are all surrounded ( O -> X)
        //Phase 3: Replace all T's in the board with O's (T -> O)
        
        int r=board.size(), c=board[0].size();
        //running dfs on each bordering row/column
        for(int i=0;i<r; i++)
            if(board[i][0]=='O')
                dfs(i, 0, r, c, board);
        for(int i=0;i<r; i++)
            if(board[i][c-1]=='O')
                dfs(i, c-1, r, c, board);
        for(int i=0;i<c; i++)
            if(board[0][i]=='O')
                dfs(0, i, r, c, board);
        for(int i=0;i<c; i++)
            if(board[r-1][i]=='O')
                dfs(r-1, i, r, c, board);
        
        //setting all surrounded O's with X's
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++)
                if(board[i][j] == 'O')
                    board[i][j]='X';
        }
        
        //setting all unsurrounded T's with O's
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++)
                if(board[i][j] == 'T')
                    board[i][j]='O';
        }
    }
};