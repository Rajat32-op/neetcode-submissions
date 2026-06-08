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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head=NULL;
        ListNode *cur;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                if(head==NULL){
                    head=list1;
                    cur=head;
                }
                else{
                    cur->next=list1;
                    cur=cur->next;
                }
                list1=list1->next;
            }
            else{
                if(head==NULL){
                    head=list2;
                    cur=head;
                }
                else{
                    cur->next=list2;
                    cur=cur->next;
                }
                list2=list2->next;
            }
        }
        if(list1!=NULL){
            if(head==NULL)return list1;
            cur->next=list1;
        }
        if(list2!=NULL){
            if(head==NULL)return list2;
            cur->next=list2;
        }
        return head;
    }
};
