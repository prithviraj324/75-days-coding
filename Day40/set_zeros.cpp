#include<bits/stdc++.h>
using namespace std;
//additional memory approach
class Solution {
public:
    void set(vector<vector<int>>& mat, int i, int j) {
        for(int x=0;x<mat.size();x++)
            mat[x][j]=0;
        for(int x=0;x<mat[0].size();x++)
            mat[i][x]=0;
    }
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> cell;
        int p=1;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == 0)
                    cell.push_back({i,j});
            }
        }
        for(auto c: cell)
            set(mat, c[0], c[1]);
    }
};

//O(1) space solution ->
class Solution2 {
public:
    //to optimise space complexity ->
    //if mat[i][j] == 0, then we set mat[i][0] = 0 and mat[0][j] =0
    //basically, first row and col store whether row[i] or col[j] must be set to 0
    //overlooked fact: need to check whether row 0/ column 0 themselves must be set to zero or not, otherwise ans might not have the first row/col set to all 0's
    //preprocess(?) whether row 0/col 0 has a zero first, then use them to store state of each row/col, then set them to 0 or not
    void setZeroes(vector<vector<int>>& mat) {
        bool setRow= false, setCol=false;
        int m=mat.size(), n=mat[0].size();
        
        for(int i=0;i<m;i++) {
            if(mat[i][0] == 0) {
                setCol = true;  //column must be set to 0 later
                break;
            }
        }
        for(int j=0;j<n;j++) {
            if(mat[0][j] == 0) {
                setRow = true;  //row " " " " "
                break;
            }
        }
        
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                if(mat[i][j] ==0) {
                    mat[i][0] = 0;  //using first row and col to store state of result matrix
                    mat[0][j] = 0;
                }
            }
        }
        
        //process everything but first row and column
        for(int i=1;i<m;i++) {
            if(mat[i][0] == 0) 
                for(int j=0;j<n;j++)
                    mat[i][j] = 0;
        }
        for(int j=1;j<n;j++) {
            if(mat[0][j] == 0)
                for(int i=0;i<m;i++)
                    mat[i][j] = 0;
        }
        
        if(setRow) {
            for(int j=0;j<n;j++)
                mat[0][j] = 0;
        }
        if(setCol) {
            for(int i=0;i<m;i++) 
                mat[i][0] = 0;
        }
    }
};