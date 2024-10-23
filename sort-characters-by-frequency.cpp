using namespace std;
#include <iostream>
#include <bits/stdc++.h>
// remove above lines when running in leetcode. 


class Solution {
public:
    bool static compareBySecond( pair<char,int> p1,  pair<char,int> p2){
        return p1.second > p2.second;
    }
    
    string frequencySort(string s) {
        map<char,int> m;
        vector<pair<char,int>> vp;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }

        for(auto it = m.begin() ;it!=m.end() ;it++){
            vp.push_back(make_pair(it->first,it->second));
        }

        sort(vp.begin(),vp.end(),compareBySecond);

        string ans="";

        for(int i=0;i<vp.size();i++){
            for(int j=0;j<(vp[i].second);j++){
                ans+=(vp[i].first);
            }
        }
        return ans;
    }
};