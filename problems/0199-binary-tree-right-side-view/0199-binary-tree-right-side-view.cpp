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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> ret;
        if (root == nullptr) return {}; // very important check
        queue<pair<TreeNode*,pair<int,int>> >q;   //  {node,  { row , col } }
        q.push({root,{0,0}});
        while( !q.empty() ){
            int sz = q.size();
            for(int i= 0; i< sz; i++){
                auto it  = q.front();
                TreeNode * node=  it.first;
                int row = it.second.second;
                int col = it.second.first;
                ret[row] = node->val;
                q.pop();

                // level.push_back(node->val);
                if( node->left) q.push({node->left,{col-1,row+1}});
                if( node->right) q.push({node->right,{col+1,row+1}});

            }            
        }
        vector<int> ans;
        for(auto it : ret){
            ans.push_back(it.second);
        }
        return ans;
    }
};