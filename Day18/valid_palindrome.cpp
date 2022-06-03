#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        int ci,cj;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while( i < j ) {
            ci=(int)s[i];
            cj=(int)s[j];
            if((ci<97 || ci>122) && (ci<48 || ci>57)) {
                i++;
                continue;
            }
            if((cj<97 || cj>122) && (cj<48 || cj>57)) {
                j--;
                continue;
            }
            if(s[i] != s[j]) 
                return false;
            i++;
            j--;
        }
        return true;
    }
};