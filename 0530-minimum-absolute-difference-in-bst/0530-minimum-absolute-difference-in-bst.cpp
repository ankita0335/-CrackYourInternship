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
    void inorder(TreeNode* root,vector<int>&v)
    {
        if(!root)   return ;
        v.push_back(root->val);
        inorder(root->left,v);
        inorder(root->right,v);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        int n=v.size();
        sort(v.begin(),v.end());
        int mini=INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            int diff=v[i+1]-v[i];
            mini=min(diff,mini);
        }
        return mini;
    }
};