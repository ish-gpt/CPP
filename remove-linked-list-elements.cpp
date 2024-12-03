using namespace std;
#include <iostream>
#include <bits/stdc++.h>

//https://leetcode.com/problems/remove-linked-list-elements/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
   void updateHead(ListNode* head, int val){
        if(head->next==nullptr) {
            return;
        } 
        
            if(head->next->val == val){
                head->next = head->next->next;
            } else {
                head = head->next;
            }
                updateHead(head,val);

    }
    ListNode* removeElements(ListNode* head, int val) {
        if( head != nullptr){
        updateHead(head,val);
        }
        return (head!=nullptr && (head->val == val)) ? head->next : head;
    }
};