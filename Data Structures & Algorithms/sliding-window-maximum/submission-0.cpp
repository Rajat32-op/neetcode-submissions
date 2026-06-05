class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(i<k-1)continue;
            ans.push_back(mp.rbegin()->first);
            mp[nums[i-k+1]]--;
            if(mp[nums[i-k+1]]==0)mp.erase(nums[i-k+1]);
        }
        return ans;
    }
};