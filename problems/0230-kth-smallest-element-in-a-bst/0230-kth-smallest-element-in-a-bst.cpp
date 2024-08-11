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

public:
    int kthSmallest(TreeNode* root, int k) {
    //vector<int> InOrder;
    int cnt = 0;
    TreeNode* cur = root;
    stack<TreeNode* > st;
    while(true ){
        if(cur != NULL){
            st.push(cur);
            cur = cur->left;
        }
        else{
            if(st.empty() ) break;
            cur = st.top();
            st.pop();
            //InOrder.push_back(cur->val);
            cnt++;
            if( cnt == k ){
                return cur->val;
            }
            cur = cur->right;
        }
    }
    //int ans = InOrder[k-1];
    return -1;  // Or throw an exception, depending on requirements
}

};