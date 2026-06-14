class comp{
public:
    bool operator()(const pair<char,int>&a,pair<char,int>&b){
        if(a.second==b.second)return a.first<b.first;
        return a.second<b.second;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;
        unordered_map<char,int>mp;
        for(char c:tasks){
            mp[c]++;
        }
        for(auto it:mp){
            pq.push({it.first,it.second});
        }
        int ans=0;
        queue<pair<char,int>>q;
        while(true){
            if(pq.empty()){
                if(q.empty())return ans;
                auto it=q.front();
                q.pop();
                ans=it.second+1;
                pq.push({it.first,mp[it.first]});
            }
            else{
                if(!q.empty()){
                    auto it=q.front();
                    if(it.second<ans){
                        q.pop();
                        pq.push({it.first,mp[it.first]});
                    }
                }
                auto it2=pq.top();
                pq.pop();
                mp[it2.first]--;
                if(mp[it2.first]>0){
                    q.push({it2.first,ans+n});
                }
                ans++;
            }
        }
        return ans;
    }
};
