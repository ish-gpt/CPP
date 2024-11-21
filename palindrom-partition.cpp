//https://leetcode.com/problems/palindrome-partitioning/

using namespace std;
#include <iostream>
#include <bits/stdc++.h>
// remove above lines when running in leetcode. 

class Solution {
public:
    bool isPalindrome(int right, int left,string s){
    // int left = 0;
    // int right = s.length() - 1;
    while (left <= right) {
        if (s[left] != s[right]) {
            // printf("\"%s\" is not palindrome.\n",
            //    str);
            return false;
        }
        left++;
        right--;
    }
    return true;
    }

    void palindromPartition(string s,int indx, vector<vector<string>> &ans, vector<string> &palin){
        if(indx==s.length()){
            ans.push_back(palin);
            return;
        }
        for(int i=indx;i<s.length();i++){
            // string str = s.substr()
            if(isPalindrome(i,indx,s)){
                palin.push_back(s.substr(indx,i-indx+1));
                palindromPartition(s,i+1,ans,palin);
                palin.pop_back();
            }
            // palin.pop_back();
        }
        // return ans;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> palin;
        palindromPartition(s,0,ans,palin);
        return ans;
    }
};