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
        op1 = max(0,depth(node->left,mx));
        op2 = max(0,depth(node->right,mx));
        mx = max(mx,op1+op2+node->val);
        return node->val + max(op1,op2);
    }

public:
    int maxPathSum(TreeNode* root) {
        int mx= INT_MIN;
        depth(root,mx);
        return mx;
    }
};