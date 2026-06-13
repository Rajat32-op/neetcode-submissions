class Solution {
public:
    string longestPalindrome(string s) {
        int res=0;
        int resLen=1;
        int n=s.length();
        for(int i=0;i<n;i++){
            int cur=1;
            int l=i-1;
            int r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
                cur+=2;
            }
            if(cur>resLen){
                resLen=cur;
                res=l+1;
            }
            l=i;
            r=i+1;
            cur=0;
            while(l>=0 && r<n &&s[l]==s[r]){
                l--;
                r++;
                cur+=2;
            }
            if(cur>resLen){
                resLen=cur;
                res=l+1;
            }
        }
        return s.substr(res,resLen);
    }
};
