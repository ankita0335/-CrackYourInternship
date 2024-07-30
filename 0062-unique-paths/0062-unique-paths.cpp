class Solution {
public:
    int dp[101][101];
    int solve(int m, int n , int i, int j)
    {
        if(i>=n || j>=m || i<0 || j<0)
            return 0;
        if(i==n-1 && j==m-1)    return 1;
        if(dp[i][j]!= -1)
            return dp[i][j];
        return dp[i][j] = solve(m, n, i+1, j) + solve(m, n, i, j+1);
    }
    int uniquePaths(int m, int n) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, 0, 0);
    }
};