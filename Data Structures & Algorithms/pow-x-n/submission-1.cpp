class Solution {
public:
    double myPow(double x, int N) {
        if(x==0)return 0;
        long long n=N;
        if(n<0){
            x=1.0/x;
            n=-n;
        }
        double ans=1.0;
        double base=x;
        while(n>0){
            if(n%2==1){
                ans*=base;
            }
            base*=base;
            n/=2;
        }
        return ans;
    }
};
