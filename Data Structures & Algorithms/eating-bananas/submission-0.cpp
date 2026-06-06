class Solution {
public:
    bool check(int mid,int h,vector<int>&a){
        int ans=0;
        for(int num:a){
            ans+=ceil((double)num/mid);
        }
        return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,h,piles))r=mid-1;
            else l=mid+1;
        }
        return  l;
    }
};
