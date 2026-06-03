class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum==-nums[i]){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1])l++;
                    while(r>l && nums[r]==nums[r+1])r--;
                }
                else if(sum<-nums[i]){
                    l++;
                }
                else r--;
            }
            while(i<n-1 && nums[i]==nums[i+1])i++;
        }
        return ans;
    }
};
