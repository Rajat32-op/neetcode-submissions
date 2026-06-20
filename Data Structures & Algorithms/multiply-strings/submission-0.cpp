class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        int n=num1.length();
        int m=num2.length();
        if(n<m)return multiply(num2,num1);
        vector<int>res(n+m+1);
        for(int i=m-1;i>=0;i--){
            int mcarry=0;
            for(int j=n-1;j>=0;j--){
                int s=(num2[i]-'0')*(num1[j]-'0')+mcarry;
                mcarry=s/10;
                s%=10;
                res[m-1-i+n-1-j]+=s;
            }
            res[n+m-1-i]+=mcarry;
        }
        string ans;
        int scarry=0;
        for(int i=0;i<n+m;i++){
            int s=res[i]+scarry;
            scarry=s/10;
            s%=10;
            ans.push_back(s+'0');
        }
        while(scarry+res[n+m]>0){
            int s=res[n+m]+scarry;
            scarry=s/10;
            s%=10;
            ans.push_back(s+'0');
        }
        reverse(ans.begin(),ans.end());
        while(*ans.begin()=='0'){
            ans.erase(ans.begin());
        }
        return ans;
    }
};
