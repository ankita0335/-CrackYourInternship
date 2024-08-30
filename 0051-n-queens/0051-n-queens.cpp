class Solution {
public:
    void backTrack(vector<vector<string>>& ans, vector<string>& res, int col, vector<int>& left, vector<int>& up, vector<int>& low,int n)
    {
        if(col == n)
        {
            ans.push_back(res);
            return ;
        }

        for(int row=0; row<n;row++)
        {
            if(left[row] == 0 && up[n-1+row-col]==0 && low[row+col ]==0)
            {
                res[row][col]= 'Q';
                left[row]=1;
                up[n-1+row-col]=1;
                low[row+col]=1;

                backTrack(ans,res,col+1, left, up, low, n);

                res[row][col]='.';
                left[row] = 0;
                up[n-1+row-col]=0;
                low[row+col]= 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> res(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            res[i] = s;
        }
        vector<int> left(n,0), updiag(2*n-1,0), lowdiag(2*n-1,0);
        backTrack(ans, res, 0, left ,updiag, lowdiag,n );
        return ans;
    }
};