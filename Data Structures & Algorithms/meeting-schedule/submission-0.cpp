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
    bool canAttendMeetings(vector<Interval>& a) {
        sort(a.begin(),a.end(),[](Interval &x,Interval &y){
            return x.start<y.start;
        });
        int e=a[0].end;
        int n=a.size();
        for(int i=1;i<n;i++){
            if(a[i].start<e){
                return false;
            }
            else{
                e=a[i].end;
            }
        }
        return true;
    }
};
