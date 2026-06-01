class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m)return false;
        vector<int>sf(26);
        vector<int>tf(26);
        for(int i=0;i<n;i++){
            sf[s[i]-'a']++;
            tf[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(sf[i]!=tf[i])return false;
        }
        return true;
    }
};
