using namespace std;
#include <iostream>
#include <bits/stdc++.h>
// remove above lines when running in leetcode. 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]] = i;
        }

        for(int i=0;i<nums.size();i++){
            if(umap.find(target-nums[i]) != umap.end() && i!=umap[target-nums[i]]){
                return {i,umap[target-nums[i]]};
            }
        }
        return {};
    }
};