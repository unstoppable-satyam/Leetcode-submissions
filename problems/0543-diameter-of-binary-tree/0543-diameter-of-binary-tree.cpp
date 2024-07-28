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
    int depth(TreeNode* node, int &mx){
        if(node == NULL ) return 0;
        int op1 = 0, op2 = 0;
        op1 = depth(node->left,mx);
        op2 = depth(node->right,mx);
        mx = max(mx,op1+op2);
        return max(1+op1,1+op2);
    }


public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia =  0;
        depth(root,dia);
        return dia;
    }
};