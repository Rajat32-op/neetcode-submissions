class Solution {
public:
    bool check(int r,int c,int n,vector<string>&cur){
        for(int j=c-1;j>=0;j--){
            if(cur[r][j]=='Q')return false;
        }
        int nr=r-1;
        int nc=c-1;
        while(nr>=0 && nc>=0){
            if(cur[nr][nc]=='Q')return false;
            nr--;
            nc--;
        }
        nr=r+1;
        nc=c-1;
        while(nc>=0 && nr<n){
            if(cur[nr][nc]=='Q')return false;
            nr++;
            nc--;
        }
        return true;
    }
    void build(int c,int n,vector<string>&cur,vector<vector<string>>&ans){
        if(c==n){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<n;i++){
            if(check(i,c,n,cur)){
                cur[i][c]='Q';
                build(c+1,n,cur,ans);
                cur[i][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>cur(n,string(n,'.'));
        build(0,n,cur,ans);
        return ans;
    }
};
