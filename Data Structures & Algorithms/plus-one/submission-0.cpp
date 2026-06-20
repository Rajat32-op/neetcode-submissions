class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            int s=digits[i]+carry;
            carry=s/10;
            s%=10;
            digits[i]=s;
        }
        if(carry!=0){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};
