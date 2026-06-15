class Solution {
public:
    vector<int>parent;
    void init(int n){
        parent.resize(n);
        for(int i=1;i<n;i++)parent[i]=i;
    }

    int find(int u){
        if(parent[u]!=u)return parent[u]=find(parent[u]);
        return u;
    }
    void join(int u,int v){
        int pu=find(u);
        int pv=find(v);
        parent[pu]=pv;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        init(n);
        for(auto it:edges){
            join(it[0],it[1]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(find(i)==i)cnt++;
        }
        return cnt;
    }
};
