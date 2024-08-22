class Solution 
{
public:
    int bfs(unordered_map<int, vector<int>>&mp, int source, int target)
    {
        queue<int>q;
        q.push(source);
        int level =0;
        vector<bool>vis(target, false);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int tmp = q.front();
                q.pop();
                if(tmp == target)
                {
                    return level;
                }
                for(auto i : mp[tmp])
                {
                    if(!vis[i])
                    {
                        q.push(i);
                        vis[i]=true;
                    }
                }
            }
            level++;
        }        
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[i].push_back(i+1);
        }
        vector<int>ans;
        for(int i= 0;i<queries.size();i++)
        {
            mp[queries[i][0]].push_back(queries[i][1]);
            int res= bfs(mp,0, n-1);
            ans.push_back(res);
        }
        return ans;
    }
};