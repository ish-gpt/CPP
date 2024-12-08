using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include <string>

//https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:
    void getParanthesis(vector<string> &ans, string possibleAns,int openParan, int closeParan){
        if(openParan==0 && closeParan==0){
            ans.push_back(possibleAns);
            return;
        }
        if(openParan){
            openParan--;
            string str1 = possibleAns;
            str1 += '(';
            getParanthesis(ans,str1,openParan, closeParan);
            openParan++;
        }
        if(closeParan > openParan){
            closeParan--;
            string str2 = possibleAns;
            str2 += ')';
            getParanthesis(ans,str2,openParan, closeParan);
            closeParan++;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string possibleAns = "";
        int openParan = n;
        int closeParan = n;
        getParanthesis(ans,possibleAns,openParan, closeParan);
        return ans;
    }
};