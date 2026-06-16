class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1,vector<pair<int,int>>());
        for(auto it:times){
            adj[it[0]].push_back({it[2],it[1]});
        }

        vector<int>dis(n+1,INT_MAX);
        set<pair<int,int>>st;
        st.insert({0,k});
        dis[k]=0;
        while(!st.empty()){
            auto it=*st.begin();
            st.erase(st.begin());
            int node=it.second;
            // cout<<node<<endl;
            int d=it.first;
            for(auto nbr:adj[node]){
                if(dis[nbr.second]==INT_MAX){
                    st.insert({d+nbr.first,nbr.second});
                    dis[nbr.second]=d+nbr.first;
                }
                else if(dis[nbr.second]>d+nbr.first){
                    st.erase({dis[nbr.second],nbr.second});
                    st.insert({d+nbr.first,nbr.second});
                    dis[nbr.second]=d+nbr.first;
                }
            }
        }
        int d=-1;
        for(int i=1;i<=n;i++){
            // cout<<dis[i]<<endl;
            d=max(d,dis[i]);
        }
        return d==INT_MAX?-1:d;
    }
};
