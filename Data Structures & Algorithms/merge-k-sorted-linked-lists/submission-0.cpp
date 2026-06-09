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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans=NULL;
        ListNode* cur;
        ListNode* temp;
        int k=lists.size();
        bool loop=true;
        while(loop){
            loop=false;
            int mn=-1;
            for(int i=0;i<k;i++){
                if(lists[i]!=NULL){
                    loop=true;
                    if(mn==-1)mn=i;
                    else{
                        if(lists[i]->val<lists[mn]->val)mn=i;
                    }
                }
            }
            if(mn!=-1){
                temp=lists[mn]->next;
                if(ans==NULL){
                    ans=lists[mn];
                    cur=ans;
                    lists[mn]->next=NULL;
                    lists[mn]=temp;
                }
                else{
                    cur->next=lists[mn];
                    lists[mn]->next=NULL;
                    lists[mn]=temp;
                    cur=cur->next;
                }
            }
        }
        return  ans;
    }
};
