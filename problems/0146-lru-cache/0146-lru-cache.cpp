class LRUCache {
public:
    
    struct Node{
        int key, val;
        Node* next, *prev;
        Node(){
            key = -1; val = -1; next = nullptr ; prev = nullptr;
            
        }
        Node(int key ,int value){
            this->key =key; val = value; next = nullptr ; prev = nullptr;
            
        }
    };

    struct DLL{
        unordered_map< int,struct Node* > mp;
        int sz;

        struct Node* dummy;
        struct Node* tail;
        
        DLL(){
            dummy = new Node();
            tail = dummy;
            sz = 0;
        }

        void deleteIfExists(int key){
            if(mp.find(key) == mp.end()  ) return;
            Node* to_del = mp[key];

            Node* prev_node = to_del->prev;
            Node* next_node = to_del->next;
            to_del->prev = nullptr ; to_del-> next = nullptr;
            if (to_del == tail) {
                tail = prev_node;
            }

            delete(to_del);
            sz--;
            mp.erase(key);

            prev_node->next = next_node;
            if( next_node ) next_node->prev= prev_node;
        }

        void deleteFirst(){
            Node* to_del = dummy->next;

            Node* prev_node = to_del->prev;
            Node* next_node = to_del->next;
            to_del->prev = nullptr ; to_del-> next = nullptr;

            if (to_del == tail) {
                tail = prev_node;
            }

            mp.erase(to_del->key);
            delete(to_del);
            sz--;
            

            prev_node->next = next_node;
            if( next_node )next_node->prev= prev_node;
        }

        void insertAtTail(int key, int val, int capacity){
            deleteIfExists(key);
            if( sz == capacity ){
                deleteFirst();
            }

            struct Node* newNode = new Node(key,val);
            newNode-> prev = tail;
            tail->next = newNode;
            tail = newNode;
            mp[key] = newNode;
            sz++;

        }

        int getVal(int key, int capacity){
            if(mp.find(key) == mp.end()) return -1;

            struct Node* cur_node = mp[key];
            int val = cur_node->val;
            insertAtTail(key,val,capacity);
            return val;
        }

        void putVal(int key, int val, int capacity){
            insertAtTail(key,val,capacity);     
        }
    };

    int cap;
    struct DLL *dll; 
    LRUCache(int capacity) {
        dll = new DLL();
        cap = capacity;
    }
    
    int get(int key) {
        return dll->getVal(key,cap);
    }
    
    void put(int key, int value) {
        dll->putVal(key,value,cap);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */