struct Node{
    private:
    bool flag = false;
    Node* links[26] = {};

    public:
    Node* getlink(char ch){
        return links[ch-'a'];
    }
    void setlink(char ch, Node * node){
        links[ch-'a'] = node;
    }
    void setFlag(){
        flag = true;
    }
    bool isEndOfWord(){
        return flag;
    }

    ~Node() {
        for (int i = 0; i < 26; i++) {
            if (links[i] != nullptr) {
                delete links[i];
                links[i] = nullptr;
            }
        }
    }
};


class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for(int i = 0;  i< word.size() ; i++){
            if( node->getlink(word[i]) == NULL) {
                node->setlink(word[i], new Node());
            }
            node = node->getlink(word[i]);
        }
        node->setFlag();
    }

    bool search(string word) {
        Node* node = root;
        for(int i = 0;  i< word.size() ; i++){
            if( node->getlink(word[i]) == NULL) {
                return false;
            }
            node = node->getlink(word[i]);
        }
        return node->isEndOfWord();
    }

    bool find(string &s, int ind, int change = 0 , Node * cur = NULL){
        if( !cur ) cur = root;
        if(ind == s.size() ) return (change == 1) && cur->isEndOfWord();
        
        if(change == 1 ){
            cur = cur->getlink(s[ind]);
            if( cur != NULL ) return find(s,ind+1,change,cur);
            else return false;
        }
        else{
            if( cur->getlink(s[ind]) ){
                bool op1 = find(s,ind+1,change,cur->getlink(s[ind]));
                bool op2 = false;
                for(int j = 0 ; j< 26; j++){
                    char ch = 'a'+j;
                    if(ch == s[ind] ) continue;
                    if(cur->getlink(ch) == NULL ) continue;
                    op2 = op2 || find(s,ind+1,1,cur->getlink(ch) );
                }
                return op1 || op2;
            }
            else{
                bool op2 = false;
                for(int j = 0 ; j< 26; j++){
                    char ch = 'a'+j;
                    if(ch == s[ind] ) continue;
                    if(cur->getlink(ch) == NULL ) continue;
                    op2 = op2 || find(s,ind+1,1,cur->getlink(ch));
                }
                return op2;
            }
        }
        return false;
    }

    ~Trie(){
        delete root;
    }
};

class MagicDictionary {
public:
    Trie * trie;
    MagicDictionary() {
        trie = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto it: dictionary){
            trie->insert(it);
        }
    }
    
    bool search(string searchWord) {
        return trie->find(searchWord,0);
    }
    ~MagicDictionary(){
        delete trie;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */