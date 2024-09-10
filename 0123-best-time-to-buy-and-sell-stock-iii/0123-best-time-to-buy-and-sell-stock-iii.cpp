class Solution {
public:
    int dp[100001][3][2];
    int solve(vector<int>& nums, int capacity,int idx, int n, int buy)
    {
        if(capacity == 0)
            return 0;
        if(idx == n)
            return 0;
        if(dp[idx][capacity][buy] != -1)
            return dp[idx][capacity][buy];
        if(buy)
        {
            return dp[idx][capacity][buy]= max( -nums[idx] + solve(nums,capacity, idx+1, n, 0) , 0+ solve(nums,capacity,idx+1,n,1));
        }
        else
        {
            return dp[idx][capacity][buy]= max( nums[idx] + solve(nums, capacity-1, idx+1, n, 1), 0+solve(nums,capacity, idx+1,n,0));
        }
    } 
    int maxProfit(vector<int>& prices)
    {
        memset(dp,-1,sizeof(dp));
        return solve(prices,2,0,prices.size(),1);
    }
};