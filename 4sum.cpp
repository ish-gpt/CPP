using namespace std;
#include <iostream>
#include <bits/stdc++.h>
// remove above lines when running in leetcode. 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<vector<int>,int> m;
        vector<vector<int>> vec;
        int len = nums.size()-1;
        long long int actualTarget = target, newTargetI, newTargetJ, finalTarget;
        int value1, value2;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            value1 = nums[i];
            newTargetI = target - nums[i];
            for(int j=i+1;j<nums.size();j++){
                value2 = nums[j];
                // newTargetJ = newTargetI;
                finalTarget = newTargetI-nums[j];
                int left=j+1  ,right=len;
                while(left<right){
                    // cout<<"L-"<<left<<"\n";
                    // cout<<"R-"<<right<<"\n";
                    if(nums[left]+nums[right]==finalTarget){
                        // cout<<"E";
                        vector<int> v({value1,value2,nums[left],nums[right]});
                        m[v]++;
                        left++;
                        right--;
                    } else if(nums[left]+nums[right]>finalTarget){
                        right--;
                        // cout<<"F";
                    } else {
                        left++;
                        // cout<<"G";
                    }
                }

            }
            target = actualTarget;
        }
        for (auto i : m) {
            vec.push_back(i.first);
        }
        return vec;
    }
};