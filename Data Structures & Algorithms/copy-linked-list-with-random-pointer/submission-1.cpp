/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* build(Node* cur,unordered_map<Node*,Node*>&mp){
        if(mp[cur]!=NULL)return mp[cur];
        Node* node=new Node(cur->val);
        mp[cur]=node;
        if(cur->next!=NULL)node->next=build(cur->next,mp);
        if(cur->random!=NULL)node->random=build(cur->random,mp);
        return node;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        unordered_map<Node*,Node*>mp;
        Node* cur=head;
        while(cur!=NULL){
            mp[cur]=NULL;
            cur=cur->next;
        }
        return build(head,mp);
    }
};
