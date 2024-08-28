class Solution 
{
public:
    int n, m;
    bool f;
    bool vst[505][505];
    vector<vector<int>> grid_i, grid_ii;
    void dfs(int i, int j)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || !grid_ii[i][j] || vst[i][j]) 
            return;
        vst[i][j] = true;
        if(!grid_i[i][j]) 
            f = false;
        dfs(i+1, j);
        dfs(i, j+1);
        dfs(i-1, j);
        dfs(i, j-1);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int ans = 0;
        grid_i = grid1, grid_ii = grid2;
        n = grid1.size(), m = grid1[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vst[i][j] and grid_ii[i][j])
                {
                    f = true;
                    dfs(i, j);
                    ans += f;
                }
            }
        }
        return ans;
    }
};