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
    bool check(TreeNode* p,TreeNode* q)
    {
        if((!p && q) || (!q && p)) return false;
        if(!p && !q)    return true;
        else
            return p->val==q->val && check(p->left,q->left) && check(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};