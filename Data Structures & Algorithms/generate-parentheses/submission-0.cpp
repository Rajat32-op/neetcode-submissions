class Solution {
public:
    void build(int open,int close,int n,string &cur,vector<string>&ans){
        if(cur.length()==2*n){
            ans.push_back(cur);
            return;
        }
        if(open<n){
            cur.push_back('(');
            build(open+1,close,n,cur,ans);
            cur.pop_back();
        }
        if(close<n && open-close>0){
            cur.push_back(')');
            build(open,close+1,n,cur,ans);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur;
        vector<string>ans;
        build(0,0,n,cur,ans);
        return ans;
    }
};
