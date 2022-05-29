#include<bits/stdc++.h>
using namespace std;
//----------------------------------------------------------------
//naive brute force solution, gives tle for sufficiently large input 
//TC:O(n*n), SC:O(1)
//----------------------------------------------------------------
class Solution {
public:
    bool share(string& a, string& b) {
        int arr1[26]={0};
        int arr2[26]={0};
        for(auto c:a)
            arr1[(int)(c - 97)]++;
        for(auto c:b)
            arr2[(int)(c - 97)]++;
        for(int i=0;i<26;i++)
            if(arr1[i] > 0 && arr2[i] > 0) return false;
        return true;
    }
    int maxProduct(vector<string>& words) {
        int max=0,prod=0;
        for(auto& s1:words) {
            for(auto& s2:words) {
                if(share(s1,s2)) {
                    prod=s1.length()*s2.length();
                    max= max>prod ? max : prod;
                }
            }
        }
        return max;
    }
};
//----------------------------------------------------------------
//slightly faster, passes all test cases but with low speed and mem%
//----------------------------------------------------------------
class Solution2 {
public:
    bool share(int i, int j, vector<string>& words, unordered_map<int,vector<int>>& m) {
        if(m.find(i) == m.end()) {
            vector<int> arr1(26,0);
            for(auto c:words[i])
                arr1[(int)(c - 97)]++;
            m.insert({i,arr1});
        }
        if(m.find(j) == m.end()) {
            vector<int> arr2(26,0);
            for(auto c:words[j])
                arr2[(int)(c - 97)]++;
            m.insert({j,arr2});
        }
        for(int x=0;x<26;x++)
            if(m[i][x] > 0 && m[j][x] > 0) return false;
        return true;
    }
    int maxProduct(vector<string>& words) {
        int max=0,prod=0;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<words.size();i++) {
            for(int j=i;j<words.size();j++) {
                if(share(i, j, words, m)) {
                    prod = words[i].length() * words[j].length();
                    //cout<<s1<<","<<s2<<","<<prod<<",";
                    max = max>prod ? max : prod;
                }
            }
        }
        return max;
    }
};
//-------------------------------
//same approach, but use actual bits to store info abt each character
//copied soln from discuss section
//----------------------------------------------------------------
class Solution3 {
public:
    bool checkCommon(bitset<26> &a, bitset<26> &b){ // function to check if two bitset are common
        for(int i=0;i<26;i++) if(a[i] && b[i]) return true; // if any of the bits are true, return true
        return false; // otherwise return false
    }
    int maxProduct(vector<string>& words) { // function to find the maximum product
        int n = words.size(); // number of words
        int ans=0; // initialize the answer
        vector<bitset<26>> chars(n); // vector of bitset
        for(int i=0;i<n;i++){ // iterate over all the words 
            for(auto &ch:words[i]) // iterate over all the characters in the words[i]
                chars[i][ch-'a'] =1; // set the bitset to 1
            for(int j=0;j<i;j++) // now check with all the other words
                if(!checkCommon(chars[i],chars[j])) // if the two words are not common
                    ans = max(ans, (int)words[i].size()*(int)words[j].size()); // update the answer
        }
        return ans; // return the answer
    }
};