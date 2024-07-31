class Solution {
public:
    void dfs(int row, int column , vector<vector<char>> &grid)
    {
        if( row < 0 || column < 0 || row >= grid.size() || column >= grid[0].size() || grid[row][column] == '0'  )
            return ;
        grid[row][column] = '0';
        dfs(row+1, column, grid);
        dfs(row,column+1,grid);
        dfs(row-1,column,grid);
        dfs(row,column-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int row=grid.size();
        int column=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                if(grid[i][j]== '1')
                {
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};