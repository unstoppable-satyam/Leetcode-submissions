/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret; // very important check

        queue<TreeNode*> q;
        q.push(root);

        int cnt=0;
        while( !q.empty() ){
            int sz = q.size();
            vector<int> level;
            for(int i= 0; i< sz; i++){
                TreeNode* node  = q.front();
                q.pop();
                level.push_back(node->val);
                if( node->left) q.push(node->left);
                if( node->right) q.push(node->right);
            }
            if(cnt&1 ) reverse(level.begin(), level.end());
            cnt++;
            ret.push_back( level );
            
        }
        return ret;
    }
};