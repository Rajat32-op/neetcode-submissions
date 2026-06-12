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
    int idx;
    TreeNode* build(int l,int r,vector<int>&preorder,vector<int>&inorder,unordered_map<int,int>&mp){
        if(idx==preorder.size())return NULL;
        if(l>r)return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        int b=mp[root->val];
        idx++;
        root->left=build(l,b-1,preorder,inorder,mp);
        root->right=build(b+1,r,preorder,inorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int n=preorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        idx=0;
        return build(0,n-1,preorder,inorder,mp);
    }
};
