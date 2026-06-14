class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length();
        if(n1+n2!=n3)return false;
        vector<vector<bool>>dp(n1+1,vector<bool>(n2+1));
        dp[n1][n2]=true;
        for(int i=n1;i>=0;i--){
            for(int j=n2;j>=0;j--){
                if(i==n1 && j==n2)continue;
                if(s1[i]==s3[i+j])dp[i][j]=dp[i+1][j];
                if(s2[j]==s3[i+j])dp[i][j]=dp[i][j]||dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
