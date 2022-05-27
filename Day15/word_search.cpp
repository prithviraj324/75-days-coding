#include<bits/stdc++.h>
using namespace std;
//self solution, fails at certain cases, not sure why
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=false;
        int m=board.size(), n=board[0].size();
        if(word.size() > m*n) return false;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == word[0])
                    ans+=dfs(board, word, 0, i, j, m, n);
                if(ans) return ans;
            }
        }
        return false;
    }
protected:
    bool dfs(vector<vector<char>>& board, string word, int index, int i, int j, int m, int n) {
        if(i<0 || j<0 || i==m || j==n || index>=word.size() || board[i][j] != word[index]) return false;
        if(index == word.size() -1 && board[i][j] == word[index]) return true;
        return (dfs(board, word, index+1, i+1, j, m, n) || dfs(board, word, index+1, i-1, j, m, n) || dfs(board, word, index+1, i, j+1, m, n) || dfs(board, word, index+1, i, j-1, m, n));
    }
};
//oddly satisfies all test cases, same approach
class Solution2 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        if(word.size() > m*n) return false;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == word[0] && dfs(board, word, 0, i, j, m, n))
                return true;
            }
        }
        return false;
    }
protected:
    bool dfs(vector<vector<char>>& board, string word, int index, int i, int j, int m, int n) {
        if(index == word.size()) return true;
        if(i<0 || j<0 || i==m || j==n || board[i][j] != word[index]) return false;

        board[i][j]='0';
        bool status = (dfs(board, word, index+1, i+1, j, m, n) || dfs(board, word, index+1, i-1, j, m, n) || dfs(board, word, index+1, i, j+1, m, n) || dfs(board, word, index+1, i, j-1, m, n));
        board[i][j]=word[index];
        return status;
    }
};