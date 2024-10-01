using namespace std;
#include <iostream>
#include <bits/stdc++.h>
// remove above lines when running in leetcode. 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max1 = INT_MIN, sum=0;
        for(int i=0 ; i<nums.size() ;i++ ){
            sum+=nums[i];
            if(sum<0){
                max1 = max(max1,sum);
                sum = 0;
            } else {
                max1 = max(max1,sum);
            }
        }
        return max1;
    }
};