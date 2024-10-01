using namespace std;
#include <iostream>
#include <bits/stdc++.h>
// remove above lines when running in leetcode. 


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<vector<int>,int> s;
        vector<vector<int>> ans;
        int len = nums.size()-1;
        int value1,target=0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            value1 = nums[i];
            target = target - nums[i];
            int left=i+1  ,right=len;
            while(left<right){
                if(nums[left]+nums[right]==target){
                    vector<int> v({value1,nums[left],nums[right]});
                    s[v]++;
                    left++;
                    right--;
                } else if(nums[left]+nums[right]>target){
                    right--;
                } else {
                    left++;
                }
            }
            target = 0;
        }
        for (auto i : s) {
            ans.push_back(i.first);
        }



        // my first approach- this was right too but was giving TLE.
        
        // for(int i=0;i<nums.size();i++){
        //     value1 = nums[i];
        //     target = target - nums[i];
        //     unordered_map<int,int> umap;
        //     for(int j=i+1;j<nums.size();j++){
        //             umap[nums[j]] = j;
        //     }
        //     for(int j=i+1;j<nums.size();j++){
        //         if(umap.find(target - nums[j]) != umap.end() && j!=umap[target - nums[j]]){
        //             value2 = nums[j];
        //             value3 = target-nums[j];
        //             vector<int> v({value1,value2,value3});
        //             sort(v.begin(),v.end());
        //             // s.insert(v);
        //             s[v]++;
        //         }
        //     }
        //     target = 0;
        // }
        // for (auto i : s) {
        //     ans.push_back(i.first);
        // }
        return ans;

    }

};