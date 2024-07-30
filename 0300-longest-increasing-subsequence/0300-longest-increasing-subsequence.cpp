class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[2501];
        int n=nums.size();
        for(int i=0;i<n;i++) 
        {
            dp[i] = 1;
        }
        if(n==0)    return 0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]= max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp,dp+n);
    }
};

//NOTE : memset initializes the memory with the value as a byte. Using memset(dp, 1, sizeof(dp)); sets each byte to 1, which will not correctly initialize each integer element to 1.