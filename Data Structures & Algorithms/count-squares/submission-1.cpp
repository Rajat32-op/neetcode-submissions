struct pair_hash{
    size_t operator()(const pair<int,int>&x)const{
        return hash<int>()(x.first)^(hash<int>()(x.second)<<1);
    }
};
class CountSquares {
public:
    unordered_map<pair<int,int>,int,pair_hash>mp;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int cnt=0;
        for(auto it:mp){
            if(it.first.second!=point[1])continue;
            int d=it.first.first-point[0];
            if(d==0)continue;
            if(mp.find({point[0],point[1]+d})!=mp.end() && mp.find({it.first.first,point[1]+d})!=mp.end()){
                cnt+=it.second*mp[{point[0],point[1]+d}]*mp[{it.first.first,point[1]+d}];
            }
            if(mp.find({point[0],point[1]-d})!=mp.end() && mp.find({it.first.first,point[1]-d})!=mp.end()){
                cnt+=it.second*mp[{point[0],point[1]-d}]*mp[{it.first.first,point[1]-d}];
            }
        }
        return cnt;
    }
};
