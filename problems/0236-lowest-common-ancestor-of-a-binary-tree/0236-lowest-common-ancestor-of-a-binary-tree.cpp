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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( !root ) return NULL;

        if( root->val == p->val || root->val == q->val ) return root;
        
        TreeNode* from_left = lowestCommonAncestor(root->left , p , q);
        TreeNode* from_right = lowestCommonAncestor(root->right , p , q);
        if( from_left && from_right ){
            return root; 
        }
        else if( from_left ){
            return from_left;
        }
        else if( from_right) {
            return from_right;
        }
        else{
            return NULL;
        }
    }
};