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
private:

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> ret;
        if (root == nullptr) return {{}}; // very important check

        queue<pair<TreeNode*,pair<int,int>> >q;   //  {node,  { row , col } }
        q.push({root,{0,0}});
        while( !q.empty() ){
            auto it  = q.front();
            TreeNode * node=  it.first;
            int row = it.second.second;
            int col = it.second.first;
    
            ret[col][row].insert(node->val);
            q.pop();

            // level.push_back(node->val);
            if( node->left) q.push({node->left,{col-1,row+1}});
            if( node->right) q.push({node->right,{col+1,row+1}});    
        }
        vector<vector<int>> ans;
        for(auto it : ret){
            vector<int> p;
            for(auto it2 : it.second){
                multiset<int> temp =  it2.second;
                for(auto it3 : temp ){
                    p.push_back(it3);
                }
            }
            ans.push_back(p);
        }
        // for(int i= 0; i<ret.size() ; i++){
        //     if(ret[i].size() != 0 ){
        //         sort(ret[i].begin(),ret[i].end());
        //         ans.push_back(ret[i]);
        //     }
        // }
        return ans;
    }
};