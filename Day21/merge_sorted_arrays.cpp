#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m+n,0);
        int i=0,j=0,k=0;
        while(i<m && j<n) {
            if(nums1[i]<=nums2[j])
                temp[k++]=nums1[i++];
            else 
                temp[k++]=nums2[j++];     
        }
        if(i<m)
            while(i<m)  temp[k++]=nums1[i++];
        else if(j<n)
            while(j<n)  temp[k++]=nums2[j++];
        
        nums1=temp;
    }
};
//O(n), inplace solution, still uses same memory acc to LC
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        
        int a=m-1;
        int b=n-1;
        int i=m+n-1;    // calculate the index of the last element of the merged array
        
        // go from the back by A and B and compare and put to the A element which is larger
        while(a>=0 && b>=0){
            if(A[a]>B[b])   A[i--]=A[a--];
            else            A[i--]=B[b--];
        }
        
        // if B is longer than A just copy the rest of B to A location, otherwise no need to do anything
        while(b>=0)         A[i--]=B[b--];
    }
};