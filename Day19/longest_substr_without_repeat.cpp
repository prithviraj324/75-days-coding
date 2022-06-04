#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<2) return s.length();
        unordered_map<char,int> m;//map of char's to their first occurence index in string
        for(int i=0;i<s.length();i++) {
            if(m.find(s[i])!=m.end()) continue;
            else m[s[i]]=i;
        }//store all indices of first occurences
        int l=0,r=0,maxlen=0;//left and right pointers
        while(r<s.length()) {
            if(m[s[r]] >= r) {//first occurence of newest char is not present in prev substring
                maxlen=max(maxlen, r-l+1);
                r++;
            }
            else if(m[s[r]] < r && m[s[r]] >= l){//1st occurence is in prev substring
                l=m[s[r]]+1;
                maxlen=max(maxlen, r-l+1);
                m[s[r]]=r;
                r++;
            }
            else {//1st occurence is before prev susbstring
                m[s[r]]=r;
                maxlen=max(maxlen, r-l+1);
                r++;
            }
        }
        return maxlen;
    }
};
//smaller, better, easier to understand solution, same approach and complexity
class Solution2 {
public:
	int lengthOfLongestSubstring(string s) 
	{
		unordered_set<char> set;
    
		int i = 0, j = 0, n = s.size(), ans = 0;
    
		while( i<n && j<n)
		{
			if(set.find(s[j]) == set.end()) //If the character does not in the set
			{
				set.insert(s[j++]); //Insert the character in set and update the j counter
				ans = max(ans, j-i); //Check if the new distance is longer than the current answer
			}
			else
			{
				set.erase(s[i++]); 
				/*If character does exist in the set, ie. it is a repeated character, 
				we update the left side counter i, and continue with the checking for substring. */
			}
		}
    
		return ans;
	}
};