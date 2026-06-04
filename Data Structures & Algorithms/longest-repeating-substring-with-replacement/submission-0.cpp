class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int n=s.length();
        int ans=0;
        for(char c='A';c<='Z';c++){
            int l=0;
            int cnt=0;
            for(int r=0;r<n;r++){
                if(s[r]!=c)cnt++;
                while(cnt>k){
                    if(s[l]!=c)cnt--;
                    l++;
                }
                ans=max(ans,r-l+1);
            }
        }
        return ans;
    }
};
