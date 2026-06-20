class Solution {
public:
    int getSum(int a, int b) {
        int c=0;
        int ans=0;
        for(int i=0;i<32;i++){
            int x=a&1;
            int y=b&1;

            int s=(x^y^c);
            c=(x&c)|(y&c)|(x&y);
            ans|=(s<<i);
            a>>=1;
            b>>=1;
        }
        return ans;

    }
};
