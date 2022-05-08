#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        
        int cl=0,cr=m-1;//column left, column right
        int cm,rm;//column middle, row middle 
        
        while (cl<=cr) {
            cout<<cl<<","<<cr<<endl;
            cm=(cl+cr)/2;
            
            if(matrix[cm][n-1]==target)
                return true;
            
            else if(matrix[cm][n-1]>target) {
                if(matrix[cm][0]<=target)
                    return binary_search(matrix[cm].begin(),matrix[cm].end(),target);
                else
                    cr=cm-1;
            }
            
            else 
                cl=cm+1;
        }
        return false;
    }
};
//----------------------------------------------------------------
//solution might look like its O(logm * logn) but its actually not because:
//there's only one case where target>col[first] AND target<col[last] hence its O(logm + logn)=O(log(mn))