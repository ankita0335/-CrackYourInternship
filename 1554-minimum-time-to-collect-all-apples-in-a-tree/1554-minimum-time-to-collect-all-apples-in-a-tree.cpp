class Solution {
public:
    int dfs(unordered_map<int, vector<int>>&mp, int curr, int parent, vector<bool>&hasApple)
    {
        int ans=0;
        for(auto child : mp[curr])
        {
            if(child == parent)
                continue;
            int timeNeeded= dfs(mp, child, curr, hasApple);
            if(timeNeeded>0 || hasApple[child] == true)
            {
                ans += timeNeeded+2;
            }
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>>mp;
        for(auto i: edges)
        {
            int u= i[0];
            int v= i[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        return dfs(mp, 0,-1, hasApple);
    }
};