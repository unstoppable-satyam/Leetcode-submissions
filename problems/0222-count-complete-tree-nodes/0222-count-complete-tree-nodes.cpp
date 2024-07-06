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
    int countNodes(TreeNode* node) {
        if(!node ) return 0;
        int lh = findLeftHeight(node);
        int rh = findRightHeight(node);
        if( lh == rh ) return (1<<lh)-1;
        return 1 + countNodes(node->left) + countNodes(node->right);  
    }

    int findLeftHeight(TreeNode * node){
        int h = 0;
        while(node){
            h++;
            node = node->left;
        }
        return h;
    }
    int findRightHeight(TreeNode * node){
        int h = 0;
        while(node){
            h++;
            node = node->right;
        }
        return h;
    }
};