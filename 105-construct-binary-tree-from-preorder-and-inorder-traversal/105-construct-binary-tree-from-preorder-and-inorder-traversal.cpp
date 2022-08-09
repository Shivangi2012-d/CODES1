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
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int i = 0;
        int j = 0;
        int pre_size = preorder.size();
        if (pre_size == 0)
        {
            return NULL;
        }

        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]);
        s.push(root);
        
        while (i < pre_size - 1)
        {
            TreeNode* node = s.top();
            if (node->val != inorder[j])
            {
                ++i;
                node->left = new TreeNode(preorder[i]);
                node = node->left;
                s.push(node);
            } 
            else
            {
                s.pop();
                ++j;
                if (s.empty() || s.top()->val != inorder[j])
                {
                    ++i;
                    node->right = new TreeNode(preorder[i]);
                    node = node->right;
                    s.push(node);
                }
            }
        }
        return root;
    }
};