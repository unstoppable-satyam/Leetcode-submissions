class MyHashSet {
public:
    int hs[1000005];
    MyHashSet() {
        fill(hs, hs+1000005,0);
    }
    
    void add(int key) {
        hs[key]=1;
    }
    
    void remove(int key) {
        hs[key] =0;
    }
    
    bool contains(int key) {
        return hs[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */