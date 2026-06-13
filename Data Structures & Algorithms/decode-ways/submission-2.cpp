class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+2);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]>='3'){
                dp[i]=dp[i+1];
            }
            else if(s[i]=='0'){
                dp[i]=0;
            }
            else{
                dp[i]=dp[i+1];
                if(s[i]=='1')dp[i]+=dp[i+2];
                else if(i!=n-1 && s[i+1]<='6')dp[i]+=dp[i+2];
            }
            cout<<dp[i]<<endl;
        }
        return dp[0];
    }
};
