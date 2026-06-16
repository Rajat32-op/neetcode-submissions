class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        for(int i=0;i<k+1;i++){
            vector<int>temp=dis;
            for(auto it:flights){
                if(dis[it[0]]!=INT_MAX){
                    temp[it[1]]=min(temp[it[1]],dis[it[0]]+it[2]);
                }
            }
            dis=temp;
        }
        return dis[dst]==INT_MAX?-1:dis[dst];
    }
};
