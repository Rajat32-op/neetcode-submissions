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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
        ListNode* cur=head;
        while(cur!=NULL){
            l++;
            cur=cur->next;
        }
        n=l-n;
        if(n==0){
            return head->next;
        }
        ListNode* prev=NULL;
        cur=head;
        for(int i=0;i<n;i++){
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        return head;
    }
};
