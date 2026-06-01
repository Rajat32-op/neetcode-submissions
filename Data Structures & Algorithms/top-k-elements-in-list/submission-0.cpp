class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int n=nums.size();
        vector<vector<int>>bucket(n+1,vector<int>());
        for(auto it:mp){
            bucket[it.second].push_back(it.first);
        }
        vector<int>ans;
        for(int i=n;i>=0 && k>0;i--){
            if(bucket[i].size()>0){
                for(int ele:bucket[i]){
                    ans.push_back(ele);
                    k--;
                    if(k==0)return ans;
                }
            }
        }
        return ans;
    }
};
