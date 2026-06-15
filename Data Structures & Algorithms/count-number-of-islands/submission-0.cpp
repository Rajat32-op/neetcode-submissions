class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&grid){
        grid[i][j]='2';
        if(i+1<grid.size()&&grid[i+1][j]=='1'){
            dfs(i+1,j,grid);
        }
        if(i-1>=0 && grid[i-1][j]=='1'){
            dfs(i-1,j,grid);
        }
        if(j+1<grid[0].size()&&grid[i][j+1]=='1'){
            dfs(i,j+1,grid);
        }
        if(j-1>=0 && grid[i][j-1]=='1'){
            dfs(i,j-1,grid);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
