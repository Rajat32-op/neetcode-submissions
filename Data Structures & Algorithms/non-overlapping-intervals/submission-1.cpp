class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        int s=a[0][0];
        int e=a[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
            if(a[i][0]<e){
                cnt++;
                e=min(e,a[i][1]);
            }
            else{
                s=a[i][0];
                e=a[i][1];
            }
        }
        return cnt;
    }
};
