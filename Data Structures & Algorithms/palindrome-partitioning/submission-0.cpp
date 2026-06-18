class Solution {
public:
    bool check(int l,int r,string &s){
        while(l<r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    void build(int start,string &s,vector<string>&cur,vector<vector<string>>&ans){
        if(start==s.length()){
            ans.push_back(cur);
            return;
        }
        int n=s.length();
        for(int i=start;i<n;i++){
            if(check(start,i,s)){
                cur.push_back(s.substr(start,i-start+1));
                // cout<<"hello";
                build(i+1,s,cur,ans);
                cur.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>cur;
        build(0,s,cur,ans);
        return ans;
    }
};
