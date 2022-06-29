#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {    //checks if s.substr(l,r) is a palindrome or not
        while (l < r) {
            if (s[l++] != s[r--]) 
                return false;
        }
        return true;
    }
    void dfs(string& s, int start, vector<string>& par, vector<vector<string>>& pars) {
        int n = s.length();
        if (start == n) {
            pars.push_back(par);    //if end of string reached, push arr of palindromes for given partition
        } else {
            for (int i = start; i < n; i++) {   //find palindrome
                if (isPalindrome(s, start, i)) {
                    par.push_back(s.substr(start, i - start + 1));  //partition into [palindrome...rest of string]
                    dfs(s, i + 1, par, pars); //pass partiion to dfs() and search for palindromse in that
                    par.pop_back(); //backtrack 
                }
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> pars;    //partitions
        vector<string> par; //partition

        dfs(s, 0, par, pars);
        return pars;
    }
};