class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(string s:strs){
            string l=to_string(s.length());
            ans+=l;
            ans.push_back('#');
            ans+=s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int idx=0;
        int n=s.length();
        vector<string>ans;
        while(idx<n){
            string ls="";
            while(s[idx]!='#'){
                ls.push_back(s[idx]);
                idx++;
            }
            int l=stoi(ls);
            idx++;
            ans.push_back(s.substr(idx,l));
            idx+=l;
        }
        return ans;
    }
};
