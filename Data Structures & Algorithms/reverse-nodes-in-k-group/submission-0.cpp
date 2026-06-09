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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head;
        int cnt=0;
        while(cur!=NULL){
            cnt++;
            if(cnt==k){
                cur=head;
                ListNode* prev=NULL;
                ListNode* temp;
                for(int i=0;i<k;i++){
                    temp=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=temp;
                }
                head->next=reverseKGroup(cur,k);
                return prev;
            }
            cur=cur->next;
        }
        return head;
    }
};
