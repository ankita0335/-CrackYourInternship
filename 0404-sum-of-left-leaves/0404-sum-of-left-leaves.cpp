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
    int solve(TreeNode* root,int &sum)
    {
        if(!root)   return 0;
        if(root->left!=nullptr &&(!root->left->left && !root->left->right))
        {
            sum+=root->left->val;
        }
        solve(root->left,sum);
        solve(root->right,sum);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        return solve(root,sum);
    }
};