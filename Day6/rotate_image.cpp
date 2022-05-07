#include<bits/stdc++.h>
using namespace std;
//insanely fast
class Solution {
public:
    void newij(int i, int j, int* a, int* b, int r) {
              //ni=new i, nj=new j
        int ni=j,nj=i;//apply transform (i,j) -> (j,i)
        nj=(r-1)-nj;  //doing origin offset for x coordinate
                      //no origin offset for ni because ni-0=ni anyways
        if(nj<0)
            nj*=-1;   //doing modulus to get +ve indices
        *a=ni;
        *b=nj;
        //dry run and see why it works out ^^
    }
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=r,temp;
        //origin is shifting from (0,0) to (0,3)
        for(int i=0;i<r;i++) {
            for(int j=i;j<c-1;j++) { //c-1 because we dont have to do for last column
                int ti=i,tj=j;  //temporary variables storing i and j value
                temp=matrix[ti][tj];//storing start of cycle value
                int a=0,b=0,x=4;
                while(x>0) {
                    newij(ti,tj,&a,&b,r);//calculating jump indices for current position
                    
                    swap(temp,matrix[a][b]);//swapping old and new values, value being overwritten is stored in temp for the next iteration
                    ti=a;//update ti and tj so we hop to that cell
                    tj=b;
                    x--;//decrement x as we have to hop only 4 times before we reach the starting cell as 4 * 90=360
                }
            }
            c--;//j=i in loop index and decrementing c so that we keep going inside the matrix layer by layer
        }
    }
};
