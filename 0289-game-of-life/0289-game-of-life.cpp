class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>>v;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int count=0;
                if(i-1>=0)  
                    count+=board[i-1][j];

                if(i-1>=0 &&  j-1>=0)
                    count +=board[i-1][j-1];

                if(i-1>=0 && j+1<m)
                    count+=board[i-1][j+1];

                if(j-1>=0)  count+=board[i][j-1];

                if(j-1>=0 && i+1<n)
                    count+=board[i+1][j-1];

                if(i+1<n)
                    count+=board[i+1][j];

                if(i+1<n && j+1<m)
                    count +=board[i+1][j+1];
                if(j+1<m)
                    count+=board[i][j+1];
                if(board[i][j]==1)
                {
                    if(count<2)
                        v.push_back({i,j});  //underpopulation
                    else if(count>3)
                        v.push_back({i,j}); //overpopulation
                }
                else{
                    if(count==3)
                        v.push_back({i,j}); //4th condition
                }
        
            }
        }
        for(auto i:v)
        {
            board[i.first][i.second]^=1; //toggle hojayega is se  0^1=1 , 1^1=0
        }
    }
};