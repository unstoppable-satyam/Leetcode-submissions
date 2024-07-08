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
    TreeNode* bstFromPreorder(vector<int>& po) {
        // build index map;
        int i= 0;
        int bound = INT_MAX;
        TreeNode* root = build(po,i,bound);
        return root;
    }

private:
    TreeNode* build(vector<int> & po,int &i, int bound){
        if(i == po.size() || po[i] > bound ) return NULL;
        TreeNode* new_node = new TreeNode(po[i++]);

        new_node->left = build(po,i,new_node->val);
        new_node->right = build(po,i,bound);
        return new_node;
    }
};