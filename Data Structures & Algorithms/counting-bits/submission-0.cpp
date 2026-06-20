class Solution {
public:
    int count(int x){
        int ans=0;
        for(int i=0;i<32;i++){
            ans+=((x>>i)&1);
        }
        return  ans;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=1;i<=n;i++){
            ans[i]=count(i);
        }
        return ans;
    }
};
