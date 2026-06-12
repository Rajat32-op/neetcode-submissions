class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
    KthLargest(int m, vector<int>& nums) {
        k=m;
        for(int num:nums){
            pq.push(num);
            if((int)pq.size()>k)pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if((int)pq.size()>k)pq.pop();
        return pq.top();
    }
};
