#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void flood(vector<vector<int>>& img, int r, int c, int ncolor,int oldColor) {//ncolor = newColor
        int m=img.size(),n=img[0].size();
        if(r < 0 || c < 0 || r == m || c == n || img[r][c] != oldColor) return;

        img[r][c]=ncolor;
        flood(img, r+1, c, ncolor, oldColor);//down
        flood(img, r-1, c, ncolor, oldColor);//up
        flood(img, r, c+1, ncolor, oldColor);//right
        flood(img, r, c-1, ncolor, oldColor);//left
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor)
            flood(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};