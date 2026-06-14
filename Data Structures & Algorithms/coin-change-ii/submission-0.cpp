class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n+1));
        for(int i=0;i<=n;i++)dp[0][i]=1;
        
        for(int i=1;i<=n;i++){

            for(int x=1;x<=amount;x++){
                dp[x][i]=dp[x][i-1];
                if(x-coins[i-1]>=0)dp[x][i]+=dp[x-coins[i-1]][i];
            }
        }
        return dp[amount][n];
    }
};
