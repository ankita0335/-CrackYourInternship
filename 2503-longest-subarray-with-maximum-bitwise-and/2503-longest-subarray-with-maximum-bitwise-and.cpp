class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxi = 0;
        int ans = 0;
        int streak = 0;
        for (int num:nums) 
        {
            if (num>maxi) 
            {
                maxi = num;
                ans = 0;
                streak = 0;
            }
            if (maxi == num) 
                streak++;
            else 
                streak = 0;
            ans = max(ans, streak);
        }
        return ans;
    }
};