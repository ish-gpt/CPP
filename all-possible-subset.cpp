using namespace std;
#include <iostream>
#include <bits/stdc++.h>

// https://leetcode.com/problems/subsets/  
// Can be done using bit manipulation also
// 000
// 001
// 010
// 011
// 100 ....and so on

class Solution {
public:
    void getAllSubsets(vector<vector<int>> &ans, vector<int> nums, vector<int> possibleSet, int indx){
        if(indx>=nums.size()){
            ans.push_back(possibleSet);
            return;
        }
        possibleSet.push_back(nums[indx]);
        getAllSubsets(ans,nums,possibleSet,indx+1);
        possibleSet.pop_back();
        getAllSubsets(ans,nums,possibleSet,indx+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> possibleSet = {};
        getAllSubsets(ans,nums,possibleSet,0);
        return ans;
    }
};