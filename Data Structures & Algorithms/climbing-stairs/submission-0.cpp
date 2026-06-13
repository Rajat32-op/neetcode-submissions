class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        int prev=1;
        int cur=2;
        for(int i=n-2;i>=1;i--){
            int sum=prev+cur;
            prev=cur;
            cur=sum;
        }
        return cur;
    }
};
