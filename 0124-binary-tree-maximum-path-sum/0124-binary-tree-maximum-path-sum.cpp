class Solution {
public:
    int maxsum;

    int solve(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int l = max(0, solve(root->left)); // Ignore negative values
        int r = max(0, solve(root->right)); // Ignore negative values
        
        int neeche_hi_mil_gya_maxsum = l + r + root->val;
        int koi_ek_achcha = max(l, r) + root->val;
        int root_maxsum = root->val;
        
        int maxi = max({neeche_hi_mil_gya_maxsum, koi_ek_achcha, root_maxsum});
        maxsum = max(maxsum, neeche_hi_mil_gya_maxsum);
        
        return koi_ek_achcha;  
    }

    int maxPathSum(TreeNode* root)
    {
        maxsum = INT_MIN;
        solve(root);
        return maxsum;
    }
};
