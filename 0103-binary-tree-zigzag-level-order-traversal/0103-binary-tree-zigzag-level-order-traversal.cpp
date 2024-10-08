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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        int f=1;
        if(!root)   return ans;
        while(!q.empty())
        {
            vector<int>curr;
            int n=q.size();
            while(n--)
            {
                TreeNode* t=q.front();
                curr.push_back(t->val);
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            if(f%2==0)  reverse(curr.begin(), curr.end());
            ans.push_back(curr); 
            f=!f;
        }
        return ans;
    }
};