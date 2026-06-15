class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        int level=0;
        int r,c;
        int x,y;
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                auto cur=q.front();
                q.pop();
                r=cur.first;
                c=cur.second;
                x=1,y=0;
                for(int j=0;j<4;j++){
                    int nr=r+x;
                    int nc=c+y;
                    if(nr<m && nc<n && nr>=0 && nc>=0 && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        cnt--;
                    }
                    int temp=x;
                    x=-y;
                    y=temp;
                }
            }
            if(!q.empty())level++;
        }
        return cnt==0?level:-1;
    }
};
