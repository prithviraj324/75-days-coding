#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=0;
        unordered_map<int,int> m;   //match element to occurence
        
        for(auto i:nums) {
            m[i]++;
            if(m[i] > 1) m[i]=1;
        }

        
        while(m.size() > 0) {
            auto p=*m.begin();
            int t=p.first, temp=t; //t used to iterate thru < and > subsequences, hence storing it in temp for later usage
            int seqlen=1;
            m.erase(t); // delete element from map as it cant occur in any other consecutive sequence
            while(m.find(t-1) != m.end()) {  // all entries less than element
                seqlen++;
                t--;
                m.erase(t);
            }
            t=temp;
            while(m.find(t+1) != m.end()) {
                seqlen++;
                t++;
                m.erase(t);
            }
            count=max(count, seqlen);
        }
        
        return count;
    }
};
//slightly faster and more compact soln using hashset
class Solution {
    public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));
        int longest = 0;
        for(auto& num : s) {
            if(s.count(num - 1)) continue;
            int j = 1;
            while(s.count(num + j)) j++;
            longest = max(longest, j);
        }
	    return longest;
    }
};