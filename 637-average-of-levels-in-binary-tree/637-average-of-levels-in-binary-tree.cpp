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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double>v;
        queue<TreeNode*>q;
        double c=0,x=0;
        q.push(root);
        
        while(q.size()>0)
        {
            int s=q.size();
            c=0;
            x=0;
            while(s--)
            {
                TreeNode* p=q.front();
                q.pop();
                c+=p->val;
                x++;
                if(p->left)
                {
                    q.push(p->left);
                }
                if(p->right)
                {
                    q.push(p->right);
                }
            }
            v.push_back(c/x);
        }
        
        return v;
        
    }
};