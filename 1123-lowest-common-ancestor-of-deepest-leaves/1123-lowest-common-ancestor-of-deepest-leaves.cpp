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
    int mx=0;
    
    int f(TreeNode* root,int depth,TreeNode* &ans)
    {
      mx=max(mx,depth);
        if(!root)
        {
            return depth;
        }
       
         int left=f(root->left,depth+1,ans);
        int right=f(root->right,depth+1,ans);
        if(left==right&&left==mx)
        {
            ans=root;
        }
        
        return max(left,right);
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
       TreeNode* ans;
       f(root,0,ans);
        return ans;
        
    }
};