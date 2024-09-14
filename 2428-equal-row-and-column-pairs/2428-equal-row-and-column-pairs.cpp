class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int cnt =0;
        int n= grid.size();
        bool f=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j< n ;j++)
            {
                f=1;
                for(int k=0;k<n;k++)
                {
                    if(grid[i][k] != grid[k][j])
                    {
                        f=0;
                        break;
                    }
                }
                cnt += f;
            }
        }
        return cnt;
    }
};