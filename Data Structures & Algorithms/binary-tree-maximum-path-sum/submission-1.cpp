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
    int ans=INT_MIN;
    int dfs(TreeNode* root){
        if(!root)return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        int s=root->val;
        if(l>0)s+=l;
        if(r>0)s+=r;
        ans=max(ans,s);
        return root->val+max(0,max(l,r));
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
