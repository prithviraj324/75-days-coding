#include<bits/stdc++.h>
using namespace std;
//very inefficient initial solution
class Solution {
public:
    unordered_set<int> s;
    bool canReach(vector<int>& arr, int pos) {
        int n=arr.size();
        if(pos<0 || pos>=n) return false;
        if(s.find(pos) == s.end())
            s.insert(pos);
        else return false;
        if(arr[pos]==0) return true;
        
        return canReach(arr, pos+arr[pos]) || canReach(arr, pos-arr[pos]);
    }
};
//better yet, mark visited indices by making val's -ve
class Solution2 {
public:
    bool reach(vector<int>& arr, int pos) {
        int n=arr.size();
        if(pos<0 || pos>=n) return false;
        if(arr[pos]<0) return false;
        if(arr[pos]==0) return true;
        arr[pos] = -arr[pos]; //visited
        return reach(arr, pos+arr[pos]) || reach(arr, pos-arr[pos]);
    }
    bool canReach(vector<int>& arr, int pos) {
        return reach(arr, pos+arr[pos]) || reach(arr, pos-arr[pos]);
    }
};