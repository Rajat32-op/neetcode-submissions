class Solution {
public:
    bool check(vector<int>&a,vector<int>&b){
        for(int i=0;i<52;i++){
            if(a[i]!=0 && a[i]>b[i])return false;
        }
        return true;
    }
    int ctoidx(char c){
        if(c>='A'&&c<='Z')return c-'A';
        return (c-'a')+26;
    }
    string minWindow(string s, string t) {
        int ans=INT_MAX;
        int minl=0;
        vector<int>ft(52);
        for(char c:t){
            ft[ctoidx(c)]++;
        }
        int l=0;
        int n=s.length();
        vector<int>fs(52);
        for(int r=0;r<n;r++){
            fs[ctoidx(s[r])]++;
            while(check(ft,fs)){
                if(r-l+1<ans){
                    ans=r-l+1;
                    minl=l;
                }
                fs[ctoidx(s[l])]--;
                l++;
            }
        }
        if(ans==INT_MAX)return "";
        return s.substr(minl,ans);
    }
};
