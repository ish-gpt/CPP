using namespace std;
#include <iostream>
#include <bits/stdc++.h>
// remove above lines when running in leetcode. 


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = left;

        while(mid<=right){
            if(nums[mid]==0){
                int temp = nums[mid];
                nums[mid] = nums[left];
                nums[left] = temp;
                left++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                int temp = nums[mid];
                nums[mid] = nums[right];
                nums[right] = temp;
                right--;
            }
        }
        
    }
};