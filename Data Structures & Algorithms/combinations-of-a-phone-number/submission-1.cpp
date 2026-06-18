class Solution {
public:
    void build(int idx,string &dig,string &cur,vector<string>&ans){
        if(idx==dig.length()){
            ans.push_back(cur);
            return;
        }
        if(dig[idx]>='2' && dig[idx]<='6'){
            int start=(dig[idx]-'2')*3;
            for(int i=0;i<3;i++){
                cur.push_back(start+i+'a');
                build(idx+1,dig,cur,ans);
                cur.pop_back();
            }
        }
        else if(dig[idx]=='7'){
            char start='p';
            for(int i=0;i<4;i++){
                cur.push_back(start+i);
                build(idx+1,dig,cur,ans);
                cur.pop_back();
            }
        }
        else if(dig[idx]=='8'){
            char start='t';
            for(int i=0;i<3;i++){
                cur.push_back(start+i);
                build(idx+1,dig,cur,ans);
                cur.pop_back();
            }
        }
        else{
            char start='w';
            for(int i=0;i<4;i++){
                cur.push_back(start+i);
                build(idx+1,dig,cur,ans);
                cur.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0)return ans;
        string cur;
        build(0,digits,cur,ans);
        return ans;
    }
};
