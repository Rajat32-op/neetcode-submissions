class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_map<int,bool>mp;
        for(int num:nums){
            mp[num]=true;
        }
        int ans=1;
        for(int num:nums){
            if(mp.find(num-1)==mp.end()){
                int cur=1;
                int ele=num+1;
                while(mp.find(ele)!=mp.end()){
                    cur++;
                    ele++;
                }
                ans=max(ans,cur);
            }
        }
        return ans;
    }
};
