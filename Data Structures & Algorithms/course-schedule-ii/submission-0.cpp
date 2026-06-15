class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        vector<vector<int>>adj(n,vector<int>());
        vector<int>indeg(n);
        for(auto it:a){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            topo.push_back(cur);
            for(auto nbr:adj[cur]){
                indeg[nbr]--;
                if(indeg[nbr]==0)q.push(nbr);
            }
        }
        if(topo.size()<n)return {};
        return topo;
    }
};
