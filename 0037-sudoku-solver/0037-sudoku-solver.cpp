class Solution {
public:
    char ch='.';
    bool isSafe(vector<vector<char>>& board, int row, int c,char k)
    {
        int n=board.size();
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==k)
                return false;
            if(board[i][c]==k)
                return false;
            if(board[(3*(row/3))+ i/3][(3*(c/3)+i%3)]==k)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==ch)
                {
                    for(char k='1';k<='9';k++)
                    {
                        if(isSafe(board,i,j,k))
                        {
                            board[i][j]=k;
                            if((solve(board)))
                                return true;
                            else
                                board[i][j]=ch;
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
