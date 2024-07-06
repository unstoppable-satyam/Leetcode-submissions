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

typedef long long ll;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0; // very important check
        queue< pair<TreeNode*, ll> >q;   //  {node,col}
        q.push({root, 0 });
        ll ans =0 ;
        while( !q.empty() ){         
            int sz = q.size();
            ll first,last;
            ll mn = q.front().second;   // minus this at each level to stop overflow

            for(int i= 0; i< sz ; i++){
                TreeNode * node = q.front().first;
                ll col =  q.front().second - mn;
                q.pop();
                if( i == 0 ) first = col;
                if( i ==  sz-1)  last = col;    // for the level that is getting deleted in this loop
                if( node->left) q.push({node->left,2*col+1});
                if( node->right) q.push({node->right,2*col+2});    
            }
            ans = max(ans, last-first+1);
        }
        return ans;  
    }
};