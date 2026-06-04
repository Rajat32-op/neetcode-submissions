class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0;
        int n=s.length();
        int ans=0;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(mp.size()!=r-l+1){
                mp[s[l]]--;
                if(mp[s[l]]==0)mp.erase(s[l]);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
