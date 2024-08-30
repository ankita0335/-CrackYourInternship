class Solution {
public:
    vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int n =maze.size();
        int m= maze[0].size();
        queue<pair<int,int>>que;
        int ans=0;
        que.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]= '+';
        while(!que.empty())
        {
            int s=que.size();
            while(s--)
            {
                pair<int,int>tmp= que.front();
                que.pop();
                int i=tmp.first;
                int j= tmp.second;
                if((tmp!= make_pair(entrance[0],entrance[1])) &&  (i==0 || i ==n-1 ||  j==0 ||j== m-1))
                    return ans;
                for(auto in: dir)
                {
                    int newi= i+in[0];
                    int newj= j+in[1];
                    if(newi >=0 && newi <n && newj >=0 && newj<m && maze[newi][newj] != '+')
                    {
                        que.push(make_pair(newi,newj));
                        maze[newi][newj] ='+';
                    }
                }
            }
            ans++;
        }
    return -1;
    }
};