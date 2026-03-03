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

    int solve(TreeNode* node, bool &check){
        if(node == NULL) return 0;
        int op1 = 0;
        int op2 = 0;
        op1 = solve(node->left,check);
        op2 = solve(node->right,check);
        if( abs(op1-op2) > 1 ) check = false;
        return 1 + max(op1,op2);
    }
    bool isBalanced(TreeNode* root) {
        bool check = true;
        int dummy = solve(root,check);
        return check;
    }
};