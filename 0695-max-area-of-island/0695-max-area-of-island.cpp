class Solution {
public:
    vector<vector<int>>dir= {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int i, int j, vector<vector<int>>&grid, int n, int m, int &count)
    {
        grid[i][j]=0;
        count++;  
        for(auto n1 : dir)
        {
            int x= i+n1[0];
            int y= j+ n1[1];
            if(x>=0 && x< n && y>=0 && y<m && grid[x][y]==1)
            { 
                dfs(x, y, grid, n, m, count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int ans=0;
        int m= grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int count=0;
                if(grid[i][j] == 1)
                {
                    dfs(i, j, grid, n, m, count);
                    ans= max(ans,count);
                }
            }
        }    
        return ans;
    }
};