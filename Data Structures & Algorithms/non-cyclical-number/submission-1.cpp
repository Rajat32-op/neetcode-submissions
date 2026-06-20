class Solution {
public:
    bool isHappy(int n) {
        int s=0;
        int prev=-1;
        int cnt=0;
        unordered_map<int,bool>mp;
        mp[n]=true;
        while(n!=1){
            int temp=n;
            cnt++;
            s=0;
            while(temp!=0){
                int dig=temp%10;
                s+=dig*dig;
                temp/=10;
            }
            n=s;
            if(mp.find(n)!=mp.end())return false;
            mp[n]=true;
        }
        return n==1;
    }
};
