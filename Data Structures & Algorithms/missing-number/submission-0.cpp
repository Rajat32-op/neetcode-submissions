class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=0;
        for(int num:nums){
            s+=num;
        }
        int n=nums.size();
        return (n*(n+1))/2-s;
    }
};
