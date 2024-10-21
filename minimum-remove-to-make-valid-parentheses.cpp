
using namespace std;
#include <iostream>
#include <bits/stdc++.h>
// remove above lines when running in leetcode. 

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> sp;
    for (int i = 0;i<s.size();i++){
        // cout << s[i];
        if(s[i]=='('){
            sp.push(make_pair('(', i));
        }
        if(s[i]==')'){
            if(!sp.empty() && sp.top().first == '('){
                sp.pop();
            } else {
                sp.push(make_pair(')', i));
            }
        }
    }
    string ans = "";
    for (int i = s.size()-1;i>=0;i--){
       if(!sp.empty() && sp.top().second == i){
           sp.pop();
       }
       else
       {
           ans += s[i];
       }
    }
    reverse(ans.begin(), ans.end());
    return ans;
    }
};


//  https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/