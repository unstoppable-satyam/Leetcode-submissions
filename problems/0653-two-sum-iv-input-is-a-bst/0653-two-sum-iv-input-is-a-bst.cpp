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
    void num(TreeNode* node, vector<int> &numbers ){
        if(node == NULL ){
            return;
        }
        num(node->left, numbers);
        numbers.push_back(node->val);
        num(node->right,numbers);
    }

    // bool solve(TreeNode* left, TreeNode* right ){

    // }

public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> numbers;
        num(root,numbers);
        int n = numbers.size();
        int i= 0 ,j = n-1;
        while( i < j ){
            if( (numbers[i] + numbers[j]) < k ){
                i++;
            }
            else if( (numbers[i] + numbers[j]) > k){
                j--;
            }
            else{
                return true;
            }
        } 
        return false;
    }
};