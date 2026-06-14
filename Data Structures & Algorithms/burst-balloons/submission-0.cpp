class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2));
        for(int l=n;l>=1;l--){
            for(int r=l;r<=n;r++){
                for(int k=l;k<=r;k++){
                    dp[l][r]=max(dp[l][r],dp[l][k-1]+dp[k+1][r]+nums[k]*nums[l-1]*nums[r+1]);
                }
            }
        }
        return dp[1][n];
    }
};
