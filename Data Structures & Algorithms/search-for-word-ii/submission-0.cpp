class node{
    public:
    node *a[26];
    bool flag=false;
    bool has(char c){
        return a[c-'a']!=NULL;
    }
    node *get(char c){
        return a[c-'a'];
    }
};

class Solution {
public:
node *root;
int m,n;
    void dfs(int r,int c,node *cur,string &word,vector<vector<char>>&board,vector<vector<bool>>&vis,set<string>&ans){
        vis[r][c]=true;
        if(cur->has(board[r][c])){
            node *next=cur->get(board[r][c]);
            word.push_back(board[r][c]);
            if(next->flag)ans.insert(word);
            if(r+1<m && !vis[r+1][c])dfs(r+1,c,next,word,board,vis,ans);
            if(r-1>=0 && !vis[r-1][c])dfs(r-1,c,next,word,board,vis,ans);
            if(c+1<n && !vis[r][c+1])dfs(r,c+1,next,word,board,vis,ans);
            if(c-1>=0 && !vis[r][c-1])dfs(r,c-1,next,word,board,vis,ans);
            word.pop_back();
        }
        vis[r][c]=false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root=new node();
       for(string s:words){
            node *cur=root;
            for(char c:s){
                if(!cur->has(c)){
                    node *next=new node();
                    cur->a[c-'a']=next;
                }
                cur=cur->get(c);
            }
            cur->flag=true;
       } 
       m=board.size();
       n=board[0].size();
        set<string>ans;
            vector<vector<bool>>vis(m,vector<bool>(n,false));
            string word;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dfs(i,j,root,word,board,vis,ans);
        }
       }
       vector<string>fin(ans.begin(),ans.end());
       return fin;
    }
};