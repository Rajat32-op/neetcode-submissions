class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& a, vector<int>& queries) {
        sort(a.begin(),a.end(),[](vector<int>&x,vector<int>&y){
            return x[0]<y[0];
        });

        int n=a.size();
        int m=queries.size();
        vector<pair<int,int>>q(m);
        for(int i=0;i<m;i++){
            q[i]={queries[i],i};
        }
        sort(q.begin(),q.end());
        vector<int>ans(m,-1);
        int idx=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int j=0;j<m;j++){
            while(idx<n && a[idx][0]<=q[j].first){
                pq.push({a[idx][1]-a[idx][0]+1,a[idx][1]});
                idx++;
            }
            while(!pq.empty()&&pq.top().second<q[j].first){
                pq.pop();
            }
            if(!pq.empty())ans[q[j].second]=pq.top().first;
        }
        return ans;
    }
};
