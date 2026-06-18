class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>mp;
        int n=hand.size();
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[hand[i]]==0)continue;
            for(int j=hand[i]+1;j<=hand[i]+groupSize-1;j++){
                if(mp[j]==0){
                    return false;
                }
            }
            for(int j=hand[i];j<=hand[i]+groupSize-1;j++){
                mp[j]--;
            }
        }
        return true;
    }
};
