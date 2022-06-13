#include<bits/stdc++.h>
using namespace std;
//brute force exponential solution
//TLE
class Solution {
public:
    int minsum(vector<vector<int>>& tri, int n, int i, int j, int sum) {
        if(i==n) return sum;
        else {
            sum+=tri[i][j];
            return min(minsum(tri, n, i+1, j, sum), minsum(tri, n, i+1, j+1, sum));
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return minsum(triangle, triangle.size(), 0, 0, 0);
    }
};
//memoized top down->
class Solution2 {
public:
    int minsum(vector<vector<int>>& tri, vector<vector<int>>& t, int n, int i, int j) {
        if(i==n-1) return tri[i][j];
        if(t[i][j]!=-1) return t[i][j];
        else
            return t[i][j] = tri[i][j] +min(minsum(tri,t,n,i+1,j), minsum(tri,t,n,i+1,j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int r=triangle.size();
        int maxcols=r;  //read constraints
        vector<vector<int>> t(r, vector<int>(r, -1)); //dp table
        return minsum(triangle, t, r, 0, 0);
    }
};
//top down tabulation->
class Solution3 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int r=triangle.size();
        //max cols=r
        vector<vector<int>> t(r, vector<int>(r,-1)); //dp table
        
        t[r-1]=triangle[r-1];  //converting base condition to initialization
        for(int i=r-2; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
				int leftsum = triangle[i][j] + t[i+1][j];
				int rightsum = triangle[i][j] + t[i+1][j+1];
				t[i][j] = min(leftsum, rightsum);
			}
        }
        return t[0][0];
    }
};
//space optimized top down->
class Solution4 {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int r=tri.size();
        for(int i=r-2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
				tri[i][j] += min(tri[i+1][j], tri[i+1][j+1]);
            }
        }
        return tri[0][0];
    }
};