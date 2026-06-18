class Solution {
public:
    bool find(int idx,int r,int c,string &word,vector<vector<bool>>&vis,vector<vector<char>>&board){
        if(board[r][c]==word[idx]){
            if(idx==word.length()-1)return true;
            int x=1,y=0,nr,nc;
            int m=vis.size();
            int n=vis[0].size();
            vis[r][c]=true;
            for(int k=0;k<4;k++){
                nr=r+x;
                nc=c+y;
                if(nr<m && nc<n && nr>=0 && nc>=0 && !vis[nr][nc] && word[idx+1]==board[nr][nc]){
                    bool b=find(idx+1,nr,nc,word,vis,board);
                    if(b)return b;
                }
                int temp=x;
                x=-y;
                y=temp;
            }
            vis[r][c]=false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(find(0,i,j,word,vis,board)){
                    return true;
                }
            }
        }
        return false;
    }
};
