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

class Codec {
public:

    // Encodes a tree to a single string.
    void serdfs(TreeNode* root,string &ans){
        if(!root){
            ans.push_back('N');
            return;
        }
        string cur=to_string(root->val);
        ans+=cur;
        ans.push_back(',');
        serdfs(root->left,ans);
        serdfs(root->right,ans);
    }
    string serialize(TreeNode* root) {
        string ans="";
        serdfs(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    int idx;
    TreeNode* build(string s){
        if(idx==s.length())return NULL;
        if(s[idx]=='N'){
            idx++;
            return NULL;
        }
        string cur;
        while(s[idx]!=','){
            cur.push_back(s[idx]);
            idx++;
        }
        idx++;
        int val=stoi(cur);
        TreeNode* root=new TreeNode(val);
        root->left=build(s);
        root->right=build(s);
        return root;
    }
    TreeNode* deserialize(string data) {
        idx=0;
        return build(data);
    }
};
