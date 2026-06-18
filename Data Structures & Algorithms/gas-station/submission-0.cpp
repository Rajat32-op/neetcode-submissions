class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gassum=accumulate(gas.begin(),gas.end(),0);
        int costsum=accumulate(cost.begin(),cost.end(),0);
        if(gassum<costsum)return -1;
        int total=0;
        int res=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            total+=gas[i]-cost[i];
            if(total<0){
                total=0;
                res=(i+1)%n;
            }
        }
        return res;
    }
};
