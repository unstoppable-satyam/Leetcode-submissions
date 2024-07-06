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
private:
    void markParent(TreeNode *root, unordered_map<TreeNode*, TreeNode * > &parent_track ){
        queue<TreeNode * > q;
        q.push(root);

        while(!q.empty() ){
            auto node = q.front();
            q.pop();
            if(node->left ){
                parent_track[node->left ]= node;
                q.push(node->left);
            }
            if( node ->right ){
                parent_track[ node->right] = node;
                q.push(node->right);
            }    
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // create track of parent
        unordered_map<TreeNode*, TreeNode * > parent_track; 
        markParent(root, parent_track);

        // we will traverse as if target node is root node
        unordered_map <TreeNode*,int > vis;   // so that the node do not come back to its parent
        queue<TreeNode* > q;
        q.push(target);
        vis[target] = 1;
        int level = 0;
        while( !q.empty()){
            if(level++ == k ) break;
            int sz = q.size();

            for(int i =0; i< sz; i++){
                auto cur = q.front() ; q.pop();
                vis[cur] = 1;

                if( cur->left && !vis[cur->left] ){
                    q.push(cur->left);
                }
                if( cur->right && !vis[cur->right] ){
                    q.push(cur->right);
                }
                if( parent_track[cur] && !vis[parent_track[cur] ] ){
                    q.push(parent_track[cur]);
                }
            }
        }

        vector<int> ret;
        while(!q.empty()){     // taking all elements at level k in a ret vector
            auto node = q.front();
            q.pop();
            ret.push_back(node->val);    
        }
        return ret;
    }
};