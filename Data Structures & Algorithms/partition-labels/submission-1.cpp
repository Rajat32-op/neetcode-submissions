class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        vector<int>ans;
        int start=0;
        int end=mp[s[0]];
        for(int i=0;i<n;i++){
            if(i==end){
                ans.push_back(end-start+1);
                start=end+1;
                if(i<n-1)end=mp[s[i+1]];
            }
            else{
                end=max(end,mp[s[i]]);
            }
        }
        return ans;
    }
};
