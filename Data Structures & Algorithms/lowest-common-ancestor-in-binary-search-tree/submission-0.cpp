/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur=root;
        int mn=min(p->val,q->val);
        int mx=max(p->val,q->val);
        while(cur!=NULL){
            int val=cur->val;
            if(val>=mn && val<=mx)return cur;
            else if(val>mx)cur=cur->left;
            else cur=cur->right;
        }
        return cur;
    }
};
