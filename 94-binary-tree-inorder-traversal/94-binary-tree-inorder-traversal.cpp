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
    vector<int> answer;
public:
    vector<int> inorderTraversal(TreeNode* root) {

        inorderTraversalHelper(root);
        return answer;        
    }

    void inorderTraversalHelper(TreeNode * root){
        if(!root) return;
        inorderTraversalHelper(root->left);
        answer.push_back(root->val);
        inorderTraversalHelper(root->right);
    }
};