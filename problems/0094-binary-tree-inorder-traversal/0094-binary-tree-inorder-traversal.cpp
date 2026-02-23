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
    vector<int> inorderTraversal(TreeNode* root) {
        if( root == nullptr ) return {};
        stack<TreeNode* > st;
        vector<int> ret;
        TreeNode* curr = root;
        while(curr || !st.empty()){
            while(curr != nullptr){
                st.push(curr);
                curr = curr->left;
                
            }
            curr = st.top();
            st.pop();
            ret.push_back(curr->val);
            curr = curr->right;
        }
        return ret;
    }
};