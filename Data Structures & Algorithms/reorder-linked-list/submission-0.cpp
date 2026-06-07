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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)return;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *second=slow->next;
        slow->next=NULL;
        ListNode *prev=NULL;
        ListNode *temp;
        while(second!=NULL){
            temp=second->next;
            second->next=prev;
            prev=second;
            second=temp;
        }
        second=prev;
        ListNode* temp2;
        while(head!=NULL && second!=NULL){
            temp=head->next;
            temp2=second->next;
            head->next=second;
            second->next=temp;
            head=temp;
            second=temp2;
        }
        
    }
};
