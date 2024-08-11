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
    bool check(TreeNode* node, long  mn , long mx ){
        if( node == NULL ) return true;
        if(node->val <= mn || node->val >= mx ) return false;
        return (check(node->left, mn , node->val) && check(node->right, node->val, mx) );
    }

public:
    bool isValidBST(TreeNode* root) {
        // with each node, have a range which is valid for it
        return check(root, -1e10, 1e10);
    }
};