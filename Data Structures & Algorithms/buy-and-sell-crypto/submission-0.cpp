class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0;
        int ans=0;
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            ans=max(ans,mx-prices[i]);
            mx=max(mx,prices[i]);
        }
        return ans;
    }
};
