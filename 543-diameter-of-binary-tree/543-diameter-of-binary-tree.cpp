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
    int ans;
public:
    int dfs(TreeNode* node) {
        if (!node) return 0; // NULL pointer, return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        ans = max(ans, l + r); // l+r represents the maximum path starting from this node which is also the diameter of this node.
        return max(l, r) + 1; // return the depth of the node
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        int temp = dfs(root);
        return ans;
        
    }
};