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
    
    void dfs(TreeNode* root,int &c,int mx)
    {
        if(!root)
        {
            return;
        }
        
        if(root->val>=mx)
        {
            c++;
        }
        mx=max(mx,root->val);
        dfs(root->left,c,mx);
        dfs(root->right,c,mx); 
        
        
        
    }
    
    int goodNodes(TreeNode* root) {
        
        
        int c=0;
        dfs(root,c,-1e5);
        
        return c;
        
    }
};