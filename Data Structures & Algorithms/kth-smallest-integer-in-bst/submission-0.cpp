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
    int ans=-1;
    int cnt=0;
    void preorder(TreeNode* root,int k){
        if(!root)return;
        if(ans!=-1)return;
        preorder(root->left,k);
        cnt++;
        if(cnt==k)ans=root->val;
        preorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        preorder(root,k);
        return ans;
    }
};
