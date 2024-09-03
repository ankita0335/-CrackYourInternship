class Solution {
public:
    vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int i,int j, vector<vector<char>>&board, int n, int m)
    {
        board[i][j]= '0';
        for(auto &neww: dir)
        {
            int x= i+ neww[0];
            int y= j+neww[1];
            if(x>=0 && x<n && y>=0 && y<m && board[x][y] == 'X')
            {
                dfs(x,y, board, n,m);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) 
    {
        int n=board.size();
        int m= board[0].size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]== 'X')
                {
                    dfs(i,j, board, n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};