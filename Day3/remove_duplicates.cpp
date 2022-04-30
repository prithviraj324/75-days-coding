/*BRUTE FORCE: just check if nums[i] is not already present in map
                            then add to new vector
                            add to map
                          else
                            continue
                          return new vector.size()
TC:N,SC:N
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x=1,cur=nums[0],i=1,res=1;//x=replace index, i=loop index
        while(i<nums.size()) {
            if(nums[i]==cur)
                i++;
            else {
                nums[x]=nums[i];
                x++;
                i++;
                cur=nums[x-1];//new value to check duplicates of
                res++;
            }
        }
        return res;
    }
};