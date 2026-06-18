class Solution {
public:
    void build(int s,int idx,vector<int>&cur,vector<int>&nums,vector<vector<int>>&ans){
        if(s==0){
            ans.push_back(cur);
            return;
        }
        int n=nums.size();
        for(int i=idx;i<n;i++){
            if(s-nums[i]>=0){
                cur.push_back(nums[i]);
                build(s-nums[i],i,cur,nums,ans);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>cur;
        vector<vector<int>>ans;
        build(target,0,cur,nums,ans);
        return ans;
    }
};
