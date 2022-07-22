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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        queue<ListNode*>temp;
        queue<ListNode*> dont_edit;
        ListNode* cur=head;
        ListNode* newCur=new ListNode();
        ListNode* newHead=newCur;
        while(cur!=NULL){
            if(cur->val<x)newCur->next=new ListNode(cur->val),newCur=newCur->next;
            cur=cur->next;
        }
        cur=head;
        while(cur!=NULL){
            if(cur->val>=x)newCur->next=new ListNode(cur->val),newCur=newCur->next;
            cur=cur->next;
        }
        return newHead->next;
    }
};