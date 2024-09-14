class Solution {
public:
    int dp[5001][71];
    int r,c;
    int solve(vector<vector<int>>&mat, int r1, int sum , int target)
    {
        if( r1== r) return abs(sum-target);
        if(dp[sum][r1] != -1)   return dp[sum][r1];
        int mini = INT_MAX;
        for(int j=0;j<c;j++)
        {
            mini = min(mini, solve(mat, r1+1, sum+mat[r1][j], target));
        }
        return dp[sum][r1] = mini;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) 
    {
        int n = mat.size();
        memset(dp, -1 , sizeof(dp));
        r= mat.size();
        c= mat[0].size();
        return solve( mat, 0, 0, target);    
    }
};