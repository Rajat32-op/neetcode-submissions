class Solution {
public:
    vector<int>parent;
    void init(int n){
        parent.resize(n+1);
        for(int i=1;i<=n;i++)parent[i]=i;
    }
    int find(int u){
        if(parent[u]!=u)return parent[u]=find(parent[u]);
        return u;
    }
    bool join(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)return false;
        parent[pu]=pv;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        init(n);
        for(auto it:edges){
            if(!join(it[0],it[1]))return it;
        }
        return {-1,-1};
    }
};
