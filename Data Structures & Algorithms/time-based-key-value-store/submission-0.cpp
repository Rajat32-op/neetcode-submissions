class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end())return "";
        auto vec=mp[key];
        auto it=upper_bound(vec.begin(),vec.end(),timestamp,[](int x,const pair<int,string>&a){
            return a.first>x;
        });
        if(it==vec.begin())return "";
        it--;
        return (*it).second;
    }
};
