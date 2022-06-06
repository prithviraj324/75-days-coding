#include<bits/stdc++.h>
using namespace std;
//brute force top-down recursive solution
class Solution {
public:
    int house(vector<int>& c, int pos) {
        if(pos>c.size()-1) return 0;
        return max(c[pos]+house(c, pos+2) , house(c, pos+1));
    }
    int rob(vector<int>& nums) {
        return house(nums, 0);
    }
};
//memoizing above solution-->
class Solution2 {
public:
    int house(vector<int>& t, vector<int>& c, int pos) {
        if(pos>c.size()-1) return 0;
        if(t[pos] != -1) return t[pos];
        int ch1=c[pos]+house(t, c, pos+2);//choice1: rob house and jump to pos+2
        int ch2=house(t, c, pos+1);//choice2: dont rob, go to next house
        t[pos]=max(ch1, ch2);
        return t[pos];
    }
    int rob(vector<int>& nums) {
        vector<int> t(nums.size(),-1);
        return house(t, nums, 0);
    }
};
//bottom up Solution
class Solution3 {
public:
    int house(vector<int>& t, vector<int>& c, int pos) {
        if(pos>c.size()-1) return 0;
        if(t[pos] != -1) return t[pos];
        int ch1=c[pos]+house(t, c, pos+2);//choice1: rob house and jump to pos+2
        int ch2=house(t, c, pos+1);//choice2: dont rob, go to next house
        t[pos]=max(ch1, ch2);
        return t[pos];
    }
    int rob(vector<int>& nums) {
        vector<int> t(nums.size()+2,-1);
        *(t.rbegin())=0;
        *(t.rbegin()+1)=0;
        for(int i=t.size()-3;i>=0;i--) 
            t[i]=max(nums[i]+t[i+2], t[i+1]);
        
        return t[0];
    }
};
