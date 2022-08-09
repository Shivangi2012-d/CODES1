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
    
    bool ans=true;
    
    int helper(TreeNode *root){
      
      //base case
      if(!root)
        return 0;
        
      //return the height of each subtree
      int left=helper(root->left);
      int right=helper(root->right);
        
      //If the heights differ more than 1 
      if(abs(left-right)>1) 
        ans=false;
        
      //return the height of this subtree
      return 1+max(left,right);
        
    }
    
    bool isBalanced(TreeNode* root){
      helper(root);
      return ans;
    }
};