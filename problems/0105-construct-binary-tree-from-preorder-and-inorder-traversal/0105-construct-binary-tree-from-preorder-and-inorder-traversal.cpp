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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i= 0; i< inorder.size() ; i++){
            mp[inorder[i]] = i;
        }
        TreeNode * root = build(preorder,0,preorder.size()-1,inorder,0, inorder.size()-1 , mp);
        return root;
    }

    TreeNode* build(vector<int>& p, int ps, int pe, vector<int> &i, int is, int ie,unordered_map<int,int> &mp ){
        //base case
        if( ps > pe || is > ie ) return NULL;

        TreeNode* node = new TreeNode(p[ps]);
        int inroot =mp[node->val];
        int numsLeft = inroot - is;   // numbers is left subtree of current node

        node->left = build(p,ps+1,ps + numsLeft , i , is , inroot-1,mp);
        node->right = build(p,ps+numsLeft+1,pe, i , inroot+1, ie, mp);
        return node;
    }
};