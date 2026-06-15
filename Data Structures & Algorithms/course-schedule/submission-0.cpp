class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {

        vector<vector<int>>adj(n,vector<int>());
        vector<int>indeg(n);
        for(auto it:a){
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        queue<int>q;
        vector<int>vis(n);
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                vis[i]=true;
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            topo.push_back(cur);
            for(auto nbr:adj[cur]){
                indeg[nbr]--;
                if(!vis[nbr] && indeg[nbr]==0){
                    q.push(nbr);
                    vis[nbr]=true;
                }
            }
        }
        return topo.size()==n;
    }
};
