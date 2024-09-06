class Solution {
public:
    vector<vector<int>>dir= {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int i, int j,vector<vector<int>>& grid, int n , int m)
    {
        if(i<0 || i>=n || j<0 || j>=m ) return false;
        if(grid[i][j]!=0)   return true;
        grid[i][j]= 2;
        bool flag=true;
        for(auto ii: dir)
        {
            int x= i+ ii[0];
            int y= j+ ii[1];
            if(!dfs(x,y,grid, n, m ))
                flag= false;
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        int count =0;
        for(int i=0;i<n; i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]== 0)
                {
                    if(dfs(i,j, grid, n, m))
                        count++;
                }
            }
        }
        return count;
    }
};