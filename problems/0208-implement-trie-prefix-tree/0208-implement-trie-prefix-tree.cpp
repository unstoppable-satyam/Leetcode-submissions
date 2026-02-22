struct Node{
    Node* Links[26] = {NULL};
    bool flag;

    void addNode(char ch,Node* node){
        Links[ch-'a'] = node;
    }
    bool contains(char ch){
        return Links[ch-'a'] != NULL;
    }

    Node* getNode(char ch){
        return Links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};



class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i= 0; i< word.length(); i++)
        {
            if(!node->contains(word[i])){
                node->addNode(word[i], new Node());
            }
            node = node->getNode(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i= 0; i< word.length(); i++)
        {
            if(!node->contains(word[i])){
                return false;
            }
            node = node->getNode(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i= 0; i< prefix.length(); i++)
        {
            if(!node->contains(prefix[i])){
                return false;
            }
            node = node->getNode(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */