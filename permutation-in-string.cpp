
using namespace std;
#include <iostream>
#include <bits/stdc++.h>
// remove above lines when running in leetcode. 

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;
        vector<int> s1_v(26,0);
        vector<int> s2_v(26,0);
        for(int i=0;i<n;i++){
            s1_v[s1[i]-'a']++;
            s2_v[s2[i]-'a']++;
        }
        if(s1_v==s2_v) return true;

        for(int i=n;i<m;i++){
            s2_v[s2[i-n]-'a']--;
            s2_v[s2[i]-'a']++;
            if(s1_v==s2_v) return true;
        }
        return false;
    }
};

// https://leetcode.com/problems/permutation-in-string/