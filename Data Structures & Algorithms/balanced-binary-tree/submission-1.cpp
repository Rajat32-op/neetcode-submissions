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
    bool ans;
    int dfs(TreeNode* root){
        if(!root)return 0;
        int r=dfs(root->right);
        int l=dfs(root->left);
        if(abs(r-l)>1)ans=false;
        return max(r,l)+1;
    }
    bool isBalanced(TreeNode* root) {
        ans=true;
        dfs(root);
        return ans;
    }
};
