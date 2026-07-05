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
        if(!root) return 0;
        ll mx = 1;
        queue<pair<ll,TreeNode*> > q;
        q.push({0LL,root});
        
        while(!q.empty()){
            int sz = q.size();
            ll mn_level = q.front().first;
            ll mx_level;
            for(int i = 0; i< sz; i++){
                auto it = q.front();
                q.pop();

                if(i == sz-1 ){
                    mx_level = it.first;
                }

                ll cur_ind = it.first - mn_level;
                auto Node = it.second;
                if(Node->left ){
                    q.push( {2*cur_ind+1LL , Node->left});
                }
                if(Node->right ){
                    q.push( {2*cur_ind+2LL , Node->right});
                }
            }
            mx = max(mx, mx_level - mn_level + 1);
        }

        return mx;
    }
};