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
        while(cur!=NULL){
            if(cur->val<x)temp.push(cur);
            else dont_edit.push(cur);
            cur=cur->next;
        }
        int n=dont_edit.size();
        // for(int i=0;i<n;i++){
        //     cout<<dont_edit.front()->val<<"\n";
        //     dont_edit.pop();
        // }
        // if(temp.empty())return head;
        // cur=temp.front();
        // temp.pop();
        // 
        cur=new ListNode();
        head=cur;
        while(!temp.empty()){
            cur->next= new ListNode(temp.front()->val);
            cur=cur->next;
            temp.pop();
        }
        //cur=cur->next;
        while(!dont_edit.empty()){
            cur->next=new ListNode(dont_edit.front()->val);
            cur=cur->next;
            dont_edit.pop();
        }
        return head->next;
    }
};