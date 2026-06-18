class Solution {
public:
    void build(int idx,vector<int>&cur,vector<int>&nums,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(cur);
            return;
        }
        int n=nums.size();
        cur.push_back(nums[idx]);
        build(idx+1,cur,nums,ans);
        cur.pop_back();
        while(idx<n-1 && nums[idx]==nums[idx+1])idx++;
        build(idx+1,cur,nums,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>cur;
        build(0,cur,nums,ans);
        return  ans;
    }
};
