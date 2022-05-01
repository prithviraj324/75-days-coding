#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int row=0;
        sort(nums.begin(),nums.end());
        if(nums.size()<3)
            return ans;
        int l,r=nums.size()-1;
        for(int i=0;i<nums.size()-1;i++) {
            l=i+1;
            r=nums.size()-1;
            while(l<r) {
                if(i>0 && nums[i]==nums[i-1] && nums[l]==ans[row-1][1] && row>0)
                    l++;
                if(nums[l]+nums[r]+nums[i]==0) {
                    ans.emplace_back(vector<int>(3,0));
                    ans[row][0]=nums[i];
                    ans[row][1]=nums[l];
                    ans[row][2]=nums[r];
                    row++;
                    break;
                }
                else if(nums[l]+nums[r]+nums[i]>0) 
                    r--;
                else
                    l++;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v0={-1,-1,-1,1};
    vector<vector<int>> v=s.threeSum(v0);
    for(auto i:v){
        for(auto j:i){
            cout<<j<<",";
        }
        cout<<endl;
    }
    return 0;
}