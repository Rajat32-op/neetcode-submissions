class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int mx=nums[0];
        int mn=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            int temp=mx;
            mx=max({nums[i],mx*nums[i],mn*nums[i]});
            mn=min({nums[i],temp*nums[i],mn*nums[i]});
            ans=max(ans,mx);
        }
        return ans;
    }
};
