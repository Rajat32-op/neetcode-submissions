/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* build(Node* cur,unordered_map<Node*,Node*>&mp){
        if(mp.find(cur)!=mp.end())return mp[cur];
        Node* newnode=new Node(cur->val);
        mp[cur]=newnode;
        for(auto nbr:cur->neighbors){
            newnode->neighbors.push_back(build(nbr,mp));
        }
        return newnode;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        unordered_map<Node*,Node*>mp;
        return build(node,mp);
    }
};
