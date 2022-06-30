#include<bits/stdc++.h>
using namespace std;
//simple, linear scan method.
//another possible solution is using dp
//      if( lcsLength(s,t) == s.length()) return true
//          ->i.e if lcs of small string and big string length is length of small string then ofc 's' is a subseq of 't'
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(), m=t.size();
        int i=m-1, j=n-1;
        while(i>=0 && j>=0) {
            if(s[j] == t[i]) {
                i--;
                j--;
            }
            else i--;
        }
        if(j < 0) return true;
        else return false;
    }
};