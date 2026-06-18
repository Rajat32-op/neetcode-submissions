class node{
public:
    node *a[26];
    bool flag;
    bool has(char c){
        return a[c-'a']!=NULL;
    }
    node *get(char c){
        return a[c-'a'];
    }
};
class WordDictionary {
public:
    node *root;
    WordDictionary() {
        root=new node();
    }
    
    void addWord(string word) {
        node *cur=root;
        for(char c:word){
            if(!cur->has(c)){
                node *next=new node();
                cur->a[c-'a']=next;
            }
            cur=cur->get(c);
        }
        cur->flag=true;
    }

    bool dfs(int idx,node *cur,string &s){
        if(idx==s.length())return cur->flag;
        if(s[idx]=='.'){
            for(int i=0;i<26;i++){
                if(cur->has(i+'a')&&dfs(idx+1,cur->get(i+'a'),s))return true;
            }
            return false;
        }
        else{
            if(cur->has(s[idx]))return dfs(idx+1,cur->get(s[idx]),s);
            else return false;
        }
        return false;
    }
    
    bool search(string word) {
        return dfs(0,root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */