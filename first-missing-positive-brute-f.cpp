using namespace std;
#include <iostream>
#include <bits/stdc++.h>

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = INT_MAX;
        int ans=-1;
        vector<int> present(100010,0);

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0 && nums[i]<=100000){
                present[nums[i]] = 1;
            }
        }
        for(int i=1;i<=100000;i++){
            if(!present[i]){
                ans = i;
                break;
            }
        }
        return ans==-1 ? 100001 : ans;
    }
};