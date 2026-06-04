class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>f1(26);
        for(char c:s1){
            f1[c-'a']++;
        }
        vector<int>f2(26);
        int n=s2.length();
        int m=s1.length();
        for(int i=0;i<n;i++){
            f2[s2[i]-'a']++;
            if(i<m-1)continue;
            bool found=true;
            for(int j=0;j<26;j++){
                if(f1[j]!=f2[j]){
                    found=false;
                    break;
                }
            }
            if(found)return true;
            f2[s2[i-m+1]-'a']--;
        }
        return false;
    }
};
