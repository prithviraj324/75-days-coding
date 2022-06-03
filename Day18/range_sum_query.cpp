#include<bits/stdc++.h>
using namespace std;
class NumMatrix {
public:
    vector<vector<int>> prefixmat;
    NumMatrix(vector<vector<int>>& matrix) {
        prefixmat.resize(matrix.size(), vector<int>(matrix[0].size()+1));
        //create prefix sum matrix which stores entire data of matirx in cumulative sum form
        for(int i=0;i<matrix.size();i++)
            prefixmat[i][0]=0;
        //added dummy first column for easier calculation of sum of elements in a row
        for(int i=0;i<matrix.size();i++) {
            for(int j=1;j<prefixmat[0].size();j++)
                prefixmat[i][j]=prefixmat[i][j-1]+matrix[i][j-1];
        }//compute prefixsum matrix
    }//doing this as constructor is only called once hence this computation is only done once
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++) {
            //cout<<prefixmat[i][col2+1]<<"-"<<prefixmat[i][col1]<<endl;
            sum+=prefixmat[i][col2+1]-prefixmat[i][col1];
        }
        //col2 is shifted to col2+1 in prefixmatrix, col1 is used as is because we have to add sum from [col1,col2]
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */