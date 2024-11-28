using namespace std;
#include <iostream>
#include <bits/stdc++.h>
//https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        int l = 0;
        int r = 0;
        int cnt=0;
        int len = 1000000000;
        int indx = -1;
        while( r < s.length()){
            if(mp[s[r]]>0){
                cnt+=1;
            }
               mp[s[r]]--; 
            while(cnt==t.length()){
                if(r-l+1<len){
                    len = r-l+1;
                    indx=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    cnt-=1;
                }
                l++;
            }
            r++;
        }
        return indx==-1 ? "" : s.substr(indx,len);

    }
};