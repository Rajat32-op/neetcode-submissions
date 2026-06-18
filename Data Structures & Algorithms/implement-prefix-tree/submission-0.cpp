class node{
    public:
    node* a[26];
    bool flag=false;
};
class PrefixTree {
public:
    node* root;
    PrefixTree() {
        root=new node();
    }
    
    void insert(string word) {
        node* cur=root;
        for(char c:word){
            if(cur->a[c-'a']==nullptr){
                node* next=new node();
                cur->a[c-'a']=next;
            }
            cur=cur->a[c-'a'];
        }
        cur->flag=true;
    }
    
    bool search(string word) {
        node* cur=root;
        for(char c:word){
            if(cur->a[c-'a']==nullptr)return false;
            cur=cur->a[c-'a'];
        }
        return cur->flag;
    }
    
    bool startsWith(string prefix) {
        node* cur=root;
        for(char c:prefix){
            if(cur->a[c-'a']==nullptr)return false;
            cur=cur->a[c-'a'];
        }
        return true;
    }
};
