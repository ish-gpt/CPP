using namespace std;
#include <iostream>
#include <bits/stdc++.h>


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int contains1 = false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) contains1 = true;
            if(nums[i]<=0 || nums[i]>nums.size()) nums[i] = 1;
        }
        if(!contains1) return 1;
        else {
            for( int i=0 ; i<nums.size() ; i++){
                if(nums[abs(nums[i])-1]<0) continue;
                else nums[abs(nums[i])-1] = (-nums[abs(nums[i])-1]);
            }
        }
        int ans = nums.size()+1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans = i+1;
                break;
            }
        }
        return ans;

    }
};
