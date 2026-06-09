class node{
public:
    int key;
    int val;
    node* next;
    node* prev;

    node(int k,int x):key(k),val(x),next(nullptr),prev(nullptr){}
};

class LRUCache {
public:
    unordered_map<int,node*> mp;
    node* head;
    node* last;
    int c;

    LRUCache(int capacity) {
        head = nullptr;
        last = nullptr;
        c = capacity;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        node* cur = mp[key];

        if(cur != head) {
            node* prev = cur->prev;
            node* next = cur->next;

            if(cur == last)
                last = prev;

            if(prev)
                prev->next = next;

            if(next)
                next->prev = prev;

            cur->prev = nullptr;
            cur->next = head;
            head->prev = cur;
            head = cur;
        }

        return cur->val;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {

            node* cur = mp[key];
            cur->val = value;

            if(cur != head) {
                node* prev = cur->prev;
                node* next = cur->next;

                if(cur == last)
                    last = prev;

                if(prev)
                    prev->next = next;

                if(next)
                    next->prev = prev;

                cur->prev = nullptr;
                cur->next = head;
                head->prev = cur;
                head = cur;
            }

            return;
        }

        node* cur = new node(key, value);

        if(head == nullptr) {
            head = cur;
            last = cur;
            mp[key] = cur;
            return;
        }

        cur->next = head;
        head->prev = cur;
        head = cur;

        mp[key] = cur;

        if(mp.size() > c) {

            node* temp = last;

            if(head == last) {
                head = nullptr;
                last = nullptr;
            }
            else {
                last = last->prev;
                last->next = nullptr;
            }

            mp.erase(temp->key);
            delete temp;
        }
    }
};