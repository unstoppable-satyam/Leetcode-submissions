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
    TreeNode* searchBST(TreeNode* root, int val) {
        if( !root ) return root;

        if( root->val < val ){
            return searchBST(root->right, val);
        }
        else if( root->val > val ){
            return searchBST(root->left, val);
        }
        else{
            return root;
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node = searchBST(root, key);
        if(!node ) return root; // not found the node

        if( node == root ){
            TreeNode* cur = root;
            if( (cur->left) && (cur->right) ){
                TreeNode* rightmost = cur->left;
                while(rightmost->right != NULL ){
                    rightmost = rightmost->right;
                }
                rightmost->right = cur->right;
                return cur->left;
                //delete cur->left;
            }
            //single child
            else if( cur->left || cur->right) {
                if( cur->left ){
                    return cur->left;
                }
                else{
                    return cur->right;
                }
            }
            // no child
            else{
                return NULL;
            }
        }
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* cur = root;
        while(cur != node ){
            if( cur->val < node->val ){
                dummy = cur;
                cur = cur->right;
            }
            else if(  cur->val > node->val){
                dummy = cur;
                cur = cur->left;
            }
        }
        //both child exists
        if( (cur->left) && (cur->right) ){
            TreeNode* rightmost = cur->left;
            while(rightmost->right != NULL ){
                rightmost = rightmost->right;
            }
            rightmost->right = cur->right;
             if(cur == dummy->left ){
                dummy->left = cur->left;
            }
            else{
                dummy->right = cur->left;
            }
            //delete cur->left;
        }
        //single child
        else if( cur->left || cur->right) {
            if( cur->left ){
                if(cur == dummy->left ){
                    dummy->left = cur->left;
                }
                else{
                    dummy->right = cur->left;
                }
            }
            else{
                if(cur == dummy->left ){
                    dummy->left = cur->right;
                }
                else{
                    dummy->right = cur->right;
                }
            }
        }
        // no child
        else{
            if(cur == dummy->left ){
                dummy->left = cur->left;
            }
            else{
                dummy->right = cur->left;
            }
        }
        return root;
    }
};