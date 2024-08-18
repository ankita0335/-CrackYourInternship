class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1];
        dp[1]=1;
        int i2=1,i3=1,i5=1;
        int mini=0;
        for(int i=2;i<=n;i++)
        {
            dp[i]=min(dp[i2]*2,min(dp[i3]*3,dp[i5]*5));
            if(dp[i]==dp[i2]*2)
                i2++;
            if(dp[i]==dp[i3]*3)
                i3++;
            if(dp[i]==dp[i5]*5)
                i5++;
        }
        return dp[n];
    }
};