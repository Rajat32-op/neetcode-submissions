class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)return false;
        vector<bool>vis(n);
        vector<vector<int>>adj(n,vector<int>());
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        q.push(0);
        int cnt=1;
        vis[0]=true;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int nbr:adj[cur]){
                if(!vis[nbr]){
                    vis[nbr]=true;
                    cnt++;
                    q.push(nbr);
                }
            }
        }
        return cnt==n;
    }
};
