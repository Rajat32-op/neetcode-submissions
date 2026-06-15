class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int level=0;
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                auto cur=q.front();
                q.pop();
                int r=cur.first;
                int c=cur.second;
                if(r+1<m && grid[r+1][c]==INT_MAX){
                    grid[r+1][c]=level+1;
                    q.push({r+1,c});
                }
                if(r-1>=0 && grid[r-1][c]==INT_MAX){
                    grid[r-1][c]=level+1;
                    q.push({r-1,c});
                }
                if(c+1<n && grid[r][c+1]==INT_MAX){
                    grid[r][c+1]=level+1;
                    q.push({r,c+1});
                }
                if(c-1>=0 && grid[r][c-1]==INT_MAX){
                    grid[r][c-1]=level+1;
                    q.push({r,c-1});
                }
            }
            level++;
        }
        
    }
};
