class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        int l=0;
        if(i+1<mat.size() && mat[i+1][j]>mat[i][j])l=max(l,dfs(i+1,j,mat,dp));
        if(i-1>=0 && mat[i-1][j]>mat[i][j])l=max(l,dfs(i-1,j,mat,dp));
        if(j+1<mat[0].size()&&mat[i][j+1]>mat[i][j])l=max(l,dfs(i,j+1,mat,dp));
        if(j-1>=0 && mat[i][j-1]>mat[i][j])l=max(l,dfs(i,j-1,mat,dp));
        return dp[i][j]=1+l;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dfs(i,j,matrix,dp));
            }
        }
        return ans;
    }
};
