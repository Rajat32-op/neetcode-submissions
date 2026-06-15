class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>&grid){
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=-1;
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            cnt++;
            int r=cur.first;
            int c=cur.second;
            if(cur.first+1<m && grid[cur.first+1][cur.second]==1){
                q.push({cur.first+1,cur.second});
                grid[cur.first+1][cur.second]=-1;
            }
            if(r-1>=0 && grid[r-1][c]==1){
                q.push({r-1,c});
                grid[r-1][c]=-1;
            }
            if(c+1<n && grid[r][c+1]==1){
                q.push({r,c+1});
                grid[r][c+1]=-1;
            }
            if(c-1>=0 && grid[r][c-1]==1){
                q.push({r,c-1});
                grid[r][c-1]=-1;
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans=max(ans,bfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};
