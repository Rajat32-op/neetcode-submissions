/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& a) {
        if(a.size()==0)return 0;
        sort(a.begin(),a.end(),[](Interval& x,Interval& y){
            return x.start<y.start;
        });
        int n=a.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(a[0].end);
        int ans=1;
        for(int i=1;i<n;i++){
            if(!pq.empty()&&pq.top()<=a[i].start){
                pq.pop();
            }
            pq.push(a[i].end);
            ans=max(ans,(int)pq.size());
        }
        return  ans;
    }
};
