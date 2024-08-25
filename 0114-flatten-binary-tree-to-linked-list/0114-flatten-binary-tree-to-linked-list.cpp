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
    void inorder(TreeNode* root, vector<int>&ans)
    {
        if(root==nullptr)   return;
        ans.push_back(root->val);
        inorder(root->left,ans);
        inorder(root->right, ans);
    }
    void flatten(TreeNode* root) 
    {
        if (root == nullptr) return;
        vector<int>ans;
        inorder(root,ans);
        TreeNode* neww = root;
        neww->val = ans[0];
        neww->left= nullptr;
        for(int i=1;i<ans.size();i++)
        {
            neww->right = new TreeNode(ans[i]);
            neww= neww->right;
        }
    }
};