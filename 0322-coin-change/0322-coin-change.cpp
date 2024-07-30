class Solution {
public:
    int dp[13][10001];
    long long solve(vector<int>& coins, int amount, int i, int n)
    {
        if(amount==0)
            return 0;
        if(i>=n || amount<0)
            return INT_MAX;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        long long res=INT_MAX;
        long long take=1LL+solve(coins,amount-coins[i],i, n);
        long long nt=solve(coins,amount, i+1 , n);
        res=min(take,nt);
        return dp[i][amount]= res;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(coins,amount,0,n);
        return ans==INT_MAX ? -1 : ans;
    }
};