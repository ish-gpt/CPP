using namespace std;
#include <iostream>
#include <bits/stdc++.h>
// remove above lines when running in leetcode. 

class Solution {
public:
    static bool cmp(vector<int> first, vector<int> second){
        if(first[0]!=second[0])
        return first[0] < second[0];
        else
        return first[1] < second[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),cmp);
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=right && intervals[i][1]>=right){
                right = intervals[i][1];
            }
            if(intervals[i][0]>right) {
                vector<int> p({left,right});
                ans.push_back(p);
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        vector<int> p({left,right});
                ans.push_back(p);
    return ans;
    }
};

