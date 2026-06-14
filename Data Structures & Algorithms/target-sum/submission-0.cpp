class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(target>sum || target<-sum)return 0;
        vector<vector<int>>dp(n+1,vector<int>(2*sum+1));
        dp[n][target+sum]=1;
        for(int i=n-1;i>=0;i--){
            for(int cur=0;cur<=2*sum;cur++){
                if(cur+nums[i]<=2*sum)dp[i][cur]=dp[i+1][cur+nums[i]];
                if(cur-nums[i]>=0)dp[i][cur]+=dp[i+1][cur-nums[i]];
            }
        }
        return dp[0][sum];
    }
};
