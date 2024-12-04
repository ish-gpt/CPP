using namespace std;
#include <iostream>
#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reversedListNode(ListNode* head) {
        if(head != nullptr && head->next ==nullptr ){
            return head;
        } 
        ListNode *newHead = reversedListNode(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
        
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *temp = head;
        if(temp != nullptr) {
            return reversedListNode(temp);
        } 
        else {
            return temp;
        }
    }
};