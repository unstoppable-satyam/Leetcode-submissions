/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void dfs( TreeNode* root , map<TreeNode* , TreeNode* > &parent ){
        if(!root) return;

        if( root->left ){
            parent[root->left] = root;
            dfs(root->left,parent);
        }
        if( root->right ){
            parent[root->right] = root;
            dfs(root->right,parent);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode* , TreeNode* > parent;
        dfs(root,parent);
        
        map<TreeNode* , int > vis;

        vector<int> ret;
        queue<pair< int ,TreeNode*> > q;
        q.push({0,target});
        vis[target] = 1 ;
        while(!q.empty()){
            int sz = q.size();
            int level = q.front().first;

            for(int i = 0;i<sz; i++){
                auto it = q.front();
                q.pop();
                if(level == k ){
                    ret.push_back(it.second->val);
                }

                auto Node = it.second;
                if(Node->left && vis[Node->left] != 1 ){
                    q.push({level+1,Node->left});
                    vis[Node->left] = 1;
                }
                if(Node->right && vis[Node->right] != 1 ){
                    q.push({level+1,Node->right});
                    vis[Node->right] = 1;
                }
                if(parent[Node] && vis[parent[Node]] != 1 ){
                    q.push({level+1,parent[Node]});
                    vis[parent[Node]] = 1;
                }
            }
            if(level == k ) break;
        }

        return ret;
        
    }
};