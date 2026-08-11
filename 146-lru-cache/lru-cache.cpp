class LRUCache {
public:
    class Node{
        public:
        int val;
        int key;
        Node* next;
        Node* prev;
        Node(int k,int v){
            this->val=v;
            this->key=k;
        }
    };
    map<int,Node*>mp;
    Node*hd,*ta;
    int sz=0;
    LRUCache(int capacity) {
        sz=capacity;
        mp.clear();
        hd=new Node(-1,-1);
        ta=new Node(-1,-1);
        hd->next=ta;
        ta->prev=hd;
    }
    Node* addNode(int k,int v){
        Node *ns=new Node(k,v);
        ns->next=hd->next;
        ns->prev=hd;
        hd->next->prev=ns;
        hd->next=ns;
        return ns;
    }
    void dele(Node*nd){
        Node* prr=nd->prev;
        Node* nxx=nd->next;
        prr->next=nxx;
        nxx->prev=prr;
    }
    int get(int key) {
        if(mp.count(key)){
            Node* b=mp[key];
            int ans=b->val;
            dele(b);
            mp[key]=addNode(key,ans);
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* b=mp[key];
            dele(b);
            mp[key]=addNode(key,value);
        }
        else{
            if(mp.size()==sz){
                mp.erase(ta->prev->key);
                dele(ta->prev);
                mp[key]=addNode(key,value);
            }
            else{
                mp[key]=addNode(key,value);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */