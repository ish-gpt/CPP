
using namespace std;
#include <iostream>
#include <bits/stdc++.h>
// remove above lines when running in leetcode. 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// https://leetcode.com/problems/reorder-list/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:

    void recurrFunc(ListNode** front, ListNode* back, bool *isBackLessThanFront, ListNode** newhead, ListNode** tail){
        if(back->next == NULL ){
            (*tail) = new ListNode(back->val);
            (*newhead) = new ListNode((*front)->val, (*tail));
            (*front) = (*front)->next;
            return;
        }
        recurrFunc(front,back->next, isBackLessThanFront,newhead, tail);
        if(*isBackLessThanFront) return;
        if((*front)==back) {
            ListNode* taill = new ListNode((*front)->val);
            (*tail)->next = taill;
            (*front) = (*front)->next;
            *isBackLessThanFront = true;
        } else {
            ListNode* taill = new ListNode(back->val);
            ListNode* head = new ListNode((*front)->val, (taill));
            (*tail)->next = head;
            (*tail) = taill;
            (*front) = (*front)->next;
            if(*(front) == back) *isBackLessThanFront = true;
        }
        
    }
    void reorderList(ListNode* head) {
        bool isBackLessThanFront = false;
        ListNode* newHead;
        ListNode* tail;
        recurrFunc(&head, head, &isBackLessThanFront, &newHead, &tail);
        while(newHead!=nullptr){
            cout<<newHead->val<<" - ";
            newHead = newHead->next;
        }
        head = newHead;
    }
};

// This code is printing correct output but we have change the original head to get correct ans
// right now correct ans is in newHead pointer. Lcgic id absolutely right.