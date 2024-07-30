class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& grid, int i, int j, int n, int m)
    {
        if(i==n-1 && j==m-1)
        {
            return dp[i][j]=grid[i][j];
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        if(i==n-1)          //last row
        {
            return dp[i][j]=grid[i][j]+solve(grid,i,j+1,n,m);
        }
        else if(j==m-1)     //last clm
            return dp[i][j]=grid[i][j]+solve(grid, i+1, j, n,m);
        else
            return dp[i][j]=min(solve(grid,i+1,j,n,m),solve(grid,i,j+1,n,m))+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
        return solve(grid,0,0,n,m);
    }
};