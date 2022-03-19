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
    bool dfs(TreeNode* root,int val)
    {
        if(!root)
        {
            return 1;
        }
        return root->val==val&&dfs(root->left,val)&&dfs(root->right,val);
    }
    bool isUnivalTree(TreeNode* root) {
        
        return dfs(root,root->val);
    }
};