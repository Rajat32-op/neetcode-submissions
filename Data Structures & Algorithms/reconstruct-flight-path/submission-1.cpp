class Solution {
public:
    void dfs(string &cur,unordered_map<string,queue<string>>&mp,vector<string>&ans){
        while(!mp[cur].empty()){
            string next=mp[cur].front();
            mp[cur].pop();
            dfs(next,mp,ans);
        }
        ans.push_back(cur);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(),tickets.end());
        unordered_map<string,queue<string>>adj;
        for(auto it:tickets){
            adj[it[0]].push(it[1]);
        }
        vector<string>ans;
        string cur="JFK";
        dfs(cur,adj,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
