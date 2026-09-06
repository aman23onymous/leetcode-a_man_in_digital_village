class LRUCache {
public:
    class Node{
    public:
        int k;
        int v;
        Node* nxt;
        Node* prv;
        Node(int ek,int ev){
            k = ek;
            v = ev;
            nxt=nullptr;
            prv=nullptr;
        }
    };
    Node*hd,*tl;
    int sz;
    map<int,Node*> mp;
    LRUCache(int capacity) {
        sz=capacity;
        hd=new Node(-1,-1);
        tl=new Node(-1,-1);
        hd->nxt=tl;
        tl->prv=hd;
    }
    void dlt(Node*cr){
        Node*fr=cr->nxt,*bc=cr->prv;
        fr->prv=cr->prv;
        bc->nxt=cr->nxt;
        delete(cr);
    }
    Node*crt(int key,int val){
        Node*nr=new Node(key,val);
        nr->nxt=hd->nxt;
        nr->prv=hd;
        hd->nxt=nr;
        nr->nxt->prv=nr;
        return nr;
    }
    
    int get(int key) {
        if(mp.count(key)){
            int vl=mp[key]->v;
            dlt(mp[key]);
            mp[key]=crt(key,vl);
            return vl;
        }
        return -1;
    }
    void put(int key, int val) {
        if(mp.count(key)){
            dlt(mp[key]);
            mp[key]=crt(key,val);
        }
        else if(mp.size()==sz){
            mp.erase(tl->prv->k);
            dlt(tl->prv);
            mp[key]=crt(key,val);
        }
        else mp[key]=crt(key,val);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */