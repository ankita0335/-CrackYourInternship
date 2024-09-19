class Solution {
public:
    int dp[30001][2];
    int solve(vector<int>&prices, int idx,int buy)
    {
        int n= prices.size();
        int profit=0;
        if(idx==n)  return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy)
        {
            profit = max(-prices[idx]+solve(prices, idx+1, 0), 0+ solve(prices, idx+1, 1));
        }
        else
        {
            profit = max(prices[idx]+ solve(prices, idx+1, 1), 0+solve(prices, idx+1, 0));
        }
        return dp[idx][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1, sizeof(dp));
        return solve(prices, 0, 1);
    }
};