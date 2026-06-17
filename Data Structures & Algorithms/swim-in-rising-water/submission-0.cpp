class Solution {
public:
    bool check(int t,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=false;
            }
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        int r,c,x,y,nr,nc;
        vis[0][0]=true;
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            r=cur.first;
            c=cur.second;
            x=1;
            y=0;
            for(int k=0;k<4;k++){
                nr=r+x;
                nc=c+y;
                if(nr<n && nc<n && nr>=0 && nc>=0 && !vis[nr][nc] && grid[nr][nc]<=t){
                    q.push({nr,nc});
                    vis[nr][nc]=true;
                    if(nr==n-1 && nc==n-1)return true;
                }
                int temp=x;
                x=-y;
                y=temp;
            }
        }
        return false;
        
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int l=max(grid[0][0],grid[n-1][n-1]);
        int r=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                r=max(r,grid[i][j]);
            }
        }
        vector<vector<bool>>vis(n,vector<bool>(n));
        while(l<=r){
            int mid=(l+r)/2;
            if(!check(mid,grid,vis)){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
};
