class comp{
public:
    bool operator()(const vector<int>&a,const vector<int>&b){
        return sqrt(a[0]*a[0]+a[1]*a[1])<sqrt(b[0]*b[0]+b[1]*b[1]);
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,comp>pq;
        for(auto it:points){
            pq.push(it);
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
