#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<int> col, posdiag, negdiag;
    void solve(vector<vector<string>>& res, int n, int r, vector<string>& board) {
        if(r==n) {
            res.push_back(board);
            return;
        }
        for(int c=0;c<n;c++) {
            if(col.count(c) || posdiag.count(r+c) || negdiag.count(r-c))
                continue;
            
            col.insert(c);
            posdiag.insert(r+c);
            negdiag.insert(r-c);
            board[r][c] = 'Q';
            solve(res, n, r+1, board);
            
            col.erase(c);
            posdiag.erase(r+c);
            negdiag.erase(r-c);
            board[r][c] = '.';
        }
    }
        
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        for(int i=0;i<n;i++)
            board[i].append(n, '.');
        //0 -> free to take
        //1 -> captured by q
        
        solve(res, n, 0, board);
        return res;
    }
};