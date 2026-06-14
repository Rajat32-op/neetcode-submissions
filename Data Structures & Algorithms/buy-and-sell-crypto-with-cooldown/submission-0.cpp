class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(2,vector<int>(n+1));
        dp[1][n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            dp[0][i]=max(dp[0][i+1],-prices[i]+dp[1][i+1]);
            dp[1][i]=max(dp[1][i+1],prices[i]+dp[0][i+2]);
        }
        return dp[0][0];
    }
};
