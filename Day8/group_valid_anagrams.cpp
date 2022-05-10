#include<bits/stdc++.h>
using namespace std;
//----------------------------------------------------------------
//brute force solution:
//tc-O(m*nlogn), sc-O(m)
//very bad solution
//----------------------------------------------------------------
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size()==1) {
            ans.push_back({strs[0]});
            return ans;
        }
        
        vector<string> temp=strs;
        unordered_map<string,vector<int>> m;

        //sort each string and put in hashmap, all anagrams will look same when sorted
        for(int i=0;i<temp.size();i++) {
            sort(temp[i].begin(),temp[i].end());//O(nlogn) time, for m strings making it O(m*nlogn)
            if(m.find(temp[i])==m.end())
                m.insert({temp[i],{i}});//storing all indices having same characters, 
            else                        //worst case might store n/i indices for i diff anagrams, making it sc:O(m) effectively
                m[temp[i]].push_back(i);
        }
        temp.clear();


        //use all indices stored
        for(auto pair:m) {//for each anagram (n/2)
            for(auto i:pair.second) {//for each index having anagram(n/2)
                temp.push_back(strs[i]);
            }
            ans.push_back(temp);
            temp.clear();
        }
        
        return ans;
    }
};
//simpler version of above code
class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};


//----------------------------------------------------------------
//better solution would be to use counting sort as we know all characters are lowercase
//since sorting normally takes n*x (x=avg length of word) time, but here we know c=[0,26] possible values
//so sorting time complexity can be reduced from nlogn to n
//----------------------------------------------------------------

class Solution3 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};