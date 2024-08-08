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
    int ans=0;
    int c=0;
    void solve(TreeNode* root, int k)
    {
        if(!root)
            return ;
        if(root->left!=nullptr)
            solve(root->left, k);
        c++;
        if(c==k)
        {
            ans= root->val;
            return ;
        }
        if(root->right!=nullptr)
            solve(root->right , k);
    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return ans;
    }
};