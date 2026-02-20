class MyHashMap {
public:
    set<pair<int,int>> st;
    MyHashMap() {
        
    }

    void put(int key, int value) {
        auto it = st.lower_bound({key,-1});
        if(it != st.end() && it->first == key ){
            if(it->second != value){
                st.erase(it);
                st.insert({key,value});
            }
        }
        else{
            st.insert({key,value});
        }
    }

    int get(int key) {
        auto it = st.lower_bound({key,-1});
        if(it != st.end() && it->first == key ){
            return it->second;
        }
        else{
            return -1;
        }
    }

    void remove(int key) {
        auto it = st.lower_bound({key,-1});
        if(it != st.end() && it->first == key ){
            st.erase(it);
        }
        else{
            // do nothing
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */