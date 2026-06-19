class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool>found(3);
        for(auto it:triplets){
            if(it[0]==target[0] && it[1]<=target[1]&&it[2]<=target[2])found[0]=true;
            if(it[1]==target[1] && it[0]<=target[0]&&it[2]<=target[2])found[1]=true;
            if(it[2]==target[2] && it[1]<=target[1]&&it[0]<=target[0])found[2]=true;
            
        }
        return found[0]&&found[1]&&found[2];
    }
};
