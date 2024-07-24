class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=abs(mini-nums[i]);
        }
        return ans;
   }
};