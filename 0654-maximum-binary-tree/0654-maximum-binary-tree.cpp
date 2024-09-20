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
    TreeNode* solve(vector<int>& nums, int strt, int end )
    {
        if(strt>  end)
            return nullptr;
        int maxi= strt;
        for(int  i= strt+1;i<= end;i++)
        {
            if(nums[i]>nums[maxi])
            {
                maxi= i;
                
            }
        }
        TreeNode* root = new TreeNode(nums[maxi]);
        root->left = solve(nums, strt, maxi-1);
        root->right = solve(nums, maxi+1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n= nums.size();
        return solve(nums, 0, n-1);
    }
};

