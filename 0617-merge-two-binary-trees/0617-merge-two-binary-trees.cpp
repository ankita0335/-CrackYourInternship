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
    TreeNode* solve(TreeNode* &root1, TreeNode* &root2)
    {
        if(!root1 && !root2)
            return nullptr;
        if(!root2 && root1)
        {
            return root1;
        }
        if(!root1 && root2) return root2;
        TreeNode* newroot=new TreeNode(root1->val+root2->val);
        newroot->left=solve(root1->left,root2->left);
        newroot->right=solve(root1->right,root2->right);
        return newroot;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1,root2);
    }
};