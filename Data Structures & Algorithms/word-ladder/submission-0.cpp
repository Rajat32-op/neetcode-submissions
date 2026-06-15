class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord)return 0;
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())return 0;
        unordered_map<string,vector<string>>mp;
        int m=beginWord.size();
        string temp=beginWord;
        for(int j=0;j<m;j++){
            temp[j]='*';
            mp[temp].push_back(beginWord);
            temp[j]=beginWord[j];
        }
        for(string s:wordList){
            string temp=s;
            for(int j=0;j<m;j++){
                temp[j]='*';
                mp[temp].push_back(s);
                temp[j]=s[j];
            }
        }
        queue<string>q;
        q.push(beginWord);
        int cnt=1;
        unordered_map<string,bool>vis;
        vis[beginWord]=true;
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                string cur=q.front();
                q.pop();
                string temp=cur;
                for(int j=0;j<m;j++){
                    temp[j]='*';
                    if(mp[temp].size()>1){
                        auto vec=mp[temp];
                        for(string s:vec){
                            if(s==endWord)return cnt+1;
                            if(vis.find(s)==vis.end()){
                                q.push(s);
                                vis[s]=true;
                            }
                        }
                    }
                    temp[j]=cur[j];
                }
            }
            cnt++;
        }
        return 0;
    }
};
