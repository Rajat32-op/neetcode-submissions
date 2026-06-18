class Solution {
public:
    void build(int idx,vector<int>&cur,vector<int>&nums,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(cur);
            return;
        }
        build(idx+1,cur,nums,ans);
        cur.push_back(nums[idx]);
        build(idx+1,cur,nums,ans);
        cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>cur;
        build(0,cur,nums,ans);
        return  ans;
    }
};
