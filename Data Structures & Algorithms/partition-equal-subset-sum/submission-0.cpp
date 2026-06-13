class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int num:nums){
            sum+=num;
        }
        if(sum%2==1)return false;
        int t=sum/2;
        vector<vector<bool>>dp(n+1,vector<bool>(t+1));
        for(int i=0;i<=n;i++)dp[i][0]=true;
        for(int i=n-1;i>=0;i--){
            for(int s=1;s<=t;s++){
                dp[i][s]=dp[i+1][s];
                if(s-nums[i]>=0)dp[i][s]=dp[i][s]||dp[i+1][s-nums[i]];
            }
        }
        return dp[0][t];
    }
};
