class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<long>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int x=1;x<=amount;x++){
            for(int i=0;i<n;i++){
                if(x-coins[i]>=0)dp[x]=min(dp[x],1L+dp[x-coins[i]]);
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
