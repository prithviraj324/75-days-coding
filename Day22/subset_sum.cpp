#include<bits/stdc++.h>
using namespace std;
class Solution{   
    //brute force exponential solution
public:
    bool ans=false;
    bool subset(vector<int>& arr, int wt, int i, int size) {
        if(i>=size) return false;
        if(arr[i]>wt) {
            return subset(arr, wt, i+1, size);
        }
        else if(arr[i] <= wt) {
            if(arr[i]-wt!=0)
                return subset(arr, wt-arr[i], i+1, size) || subset(arr, wt, i+1, size);//choose or dont choose
            else
                return true;
        }
    }
    bool isSubsetSum(vector<int> arr, int sum){
        if(arr.size()==1) return arr[0]==sum;
        int n=arr.size();
        return subset(arr, sum, 0, n);
    }
};
//----------------------------------------------------------------
//memoized top down
//TC: O(m*n = sum*n), SC: O(sum*N)
//----------------------------------------------------------------
class Solution2{   
public:
    bool ans=false;
    bool subset(vector<vector<bool>>& t, vector<int>& arr, int wt, int i, int size) {
        if(i<=0 || wt<=0) return false;
        if(t[i][wt] != NULL) return t[i][wt];   
        if(arr[i]>wt) {
            t[i][wt]=subset(t, arr, wt, i-1, size);
            return t[i][wt];
        }
        else if(arr[i] <= wt) {
            if(arr[i]-wt!=0) {
                t[i][wt]=subset(t, arr, wt-arr[i], i-1, size) || subset(t, arr, wt, i-1, size);//choose or dont choose
                return t[i][wt];
            }
            else
                return true;
        }
    }
    bool isSubsetSum(vector<int> arr, int sum){
        if(arr.size()==1) return arr[0]==sum;
        int n=arr.size();
        vector<vector<bool>> t(n+1, vector<bool>(sum+1,NULL));//sum+1 * n+1
        return subset(t, arr, sum, n-1, n);
    }
}; 
//----------------------------------------------------------------
//iterative bottom up Solution
//TC, SC are same as above, just lesser stack space
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        bool a[arr.size()+1][sum+1];
        for(int i =0;i<arr.size()+1;i++)
            a[i][0]=true;
        for(int j=0;j<sum+1;j++)
            a[0][j]=false;
        for(int i =1;i<arr.size()+1;i++){
            for(int j =1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    a[i][j] = a[i-1][j-arr[i-1]] || a[i-1][j];
                }else{
                   a[i][j] = a[i-1][j];
                }
            }
        }
        return a[arr.size()][sum];
    }
};