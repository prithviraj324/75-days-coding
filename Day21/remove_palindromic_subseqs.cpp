#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==1) return 1;
        int i=0,j=s.size()-1;
        while(i<j) {//checking if whole string itself is palindrome
            if(s[i] != s[j])
                break;
            i++;
            j--;
        }
        if(i>=j) //i.e. string is a palindrome
            return 1;
        //else condition-> all a's are one subsequence, all b's are another subsequence, hence max 2 steps otherwise
        else return 2;
    }
};