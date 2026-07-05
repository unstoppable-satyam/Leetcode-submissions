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
    int height(TreeNode* root ){
        if(!root) return 0;
        return 1 + height(root->left);

    }

    bool exists(int i , int height_tree , TreeNode* root){
        vector<int> move_right(height_tree, 0);
        int cnt = height_tree - 1;
        while(i > 0 && cnt > 0 ){
            if(i%2 == 0 ){
                move_right[cnt--] = 1;
            }
            else{
                move_right[cnt--] = 0;
            }
            i = (i-1)/2;
        }

        TreeNode* node = root;
        int lev = 1;
        while(lev < height_tree ){
            if(move_right[lev] ){
                node = node->right;
                if( !node ) return false;
            }
            else{
                node = node->left;
                if( !node ) return false;
            }
            lev++;
        }
        return true;
    }

    int countNodes(TreeNode* root) {
        
        int height_tree = height(root);
        if(height_tree == 0 ) return 0;

        cout<<" height_tree "<<height_tree<<endl;
        int l = (1<< (height_tree-1) ) - 1;
        int r = (1<< (height_tree) ) - 2;

        cout<<" l "<<l<<". r "<<r<<endl;
        while ( r-l > 1 ){
            int mid = (l+r)/2;
            cout<<" mid "<<mid<<endl;
            if( exists(mid, height_tree , root)){
                l = mid;
            }
            else{
                r = mid;
            }
            cout<<" l "<<l<<". r "<<r<<endl;
        }
        if( exists(r, height_tree , root) ) return r+1;
        else return l+1;

    }
};