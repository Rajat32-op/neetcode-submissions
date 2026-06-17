class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>>adj(26,vector<int>());
        int n=words.size();
        vector<int>indeg(26,-1);
        for(string s:words){
            for(char c:s){
                indeg[c-'a']=0;
            }
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(indeg[i]==0)cnt++;
        }
        string ans="";
        for(int i=1;i<n;i++){
            int idx1=0;
            int idx2=0;
            int l1=words[i].length();
            int l2=words[i-1].length();
            bool found=false;
            while(idx1<l1 && idx2<l2){
                if(words[i][idx1]!=words[i-1][idx2]){
                    found=true;
                    adj[words[i-1][idx2]-'a'].push_back(words[i][idx1]-'a');
                    indeg[words[i][idx1]-'a']++;
                    break;
                }
                idx1++;
                idx2++;
            }
            if(!found){
                if(l2>l1)return ans;
            }
        }
        queue<int>q;
        for(int i=0;i<26;i++){
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            ans.push_back(cur+'a');
            for(int nbr:adj[cur]){
                indeg[nbr]--;
                if(indeg[nbr]==0)q.push(nbr);
            }
        }
        return ans.size()==cnt?ans:"";
    }
};
