#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    Node() {
        memset(links, 0, sizeof(links));
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void deleteEnd() {
        cntEndWith--;
    }

    void reducePrefix() {
        cntPrefix--;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
};

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
class Solution {
public: 
    vector<string> ret;
    void dfs(int i, int j, int n, int m, string &temp, vector<vector<char>>& board, vector<vector<int>> &vis, Node * node){    
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] ) return;
        if (!node || !node->containsKey(board[i][j])) return;

        node = node->get(board[i][j]);
        temp.push_back(board[i][j]);

        if (node->cntEndWith > 0) {
            ret.push_back(temp);
            node->cntEndWith = 0;   // avoid duplicates
        }

        vis[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int newi = i + dx[k];
            int newj = j + dy[k];
            dfs(newi, newj, n, m, temp, board, vis, node);
        }
        vis[i][j] = 0;
        temp.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie * trie = new Trie();
        for(auto it : words){
            trie->insert(it);
        }
        
        int n = board.size() , m = board[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                Node *node = trie->root; 
                vector<vector<int>> vis(n , vector<int> (m,0));
                string temp;
                dfs(i,j,n,m,temp,board,vis,node);
            }
        }
        return ret;
    }
};