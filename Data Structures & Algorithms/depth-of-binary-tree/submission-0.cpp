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
    int ans=0;
    void dfs(TreeNode* root,int cur){
        if(!root)return;
        ans=max(ans,cur);
        dfs(root->right,cur+1);
        dfs(root->left,cur+1);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        dfs(root,1);
        return ans;
    }
};
