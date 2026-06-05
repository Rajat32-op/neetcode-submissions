class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>>car(n);
        for(int i=0;i<n;i++){
            car[i]={position[i],speed[i]};
        }
        sort(car.begin(),car.end());
        double t=(double)(target-car[n-1].first)/car[n-1].second;
        int ans=1;
        for(int i=n-2;i>=0;i--){
            double cur=(double)(target-car[i].first)/car[i].second;
            if(cur>t){
                t=cur;
                ans++;
            }
        }
        return ans;
    }
};
