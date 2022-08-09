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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> list;
        
        if (root == nullptr) return list;
        
        std::queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            std::vector<int> currentList;
            int size = queue.size();
            
            for (int i = 0; i < size; i++) {
                TreeNode* current = queue.front();
                queue.pop();
                
                currentList.push_back(current->val);
                if (current->left != nullptr) queue.push(current->left);
                if (current->right != nullptr) queue.push(current->right);
            }
            
            list.push_back(currentList);
        }
        
        return list;
    }
};